#include <stdio.h>
#include <stdlib.h>
#pragma GCC diagnostic ignored "-Wunused-result"
#define VR 0

int edges[100][100];
int bestBlack[100];
int nNodes;
int best;
int nBlack;

int propagate (int nodeNumber, int color[]);
void backtrack (int, int[]);
void process_solution(int[]);

int main(void) {
  int numberOfCases;
  scanf ("%d", &numberOfCases);
  if (VR)
    printf ("cases:%d\n", numberOfCases);
  int caseCounter;
  for (caseCounter = 0; caseCounter < numberOfCases; caseCounter++)
    {
      int nEdges;
      scanf("%d %d", &nNodes, &nEdges);
      if (VR)
	printf("nodes:%d edges:%d\n", nNodes, nEdges);
      int edgeCounter;
      for (edgeCounter=0; edgeCounter < nEdges; edgeCounter++) {
	int first, second;
	scanf("%d %d", &first, &second);
	edges[first-1][second-1] = 1;
	edges[second-1][first-1] = 1;
      }

      int color[100];
      int counter;
      for (counter=0; counter < nNodes; counter++) 
	color[counter] = -1;

      best = 0;
      nBlack = 0;
      backtrack(0, color);

      printf("%d\n%d", best, bestBlack[0]+1);
      for (counter=1; counter < best; counter++)
	printf(" %d", bestBlack[counter]+1);
      printf("\n");
      
    }
  return 0;
}

void backtrack(int nodeNumber, int prevColor[]) {
  int counter;
  int prevNBlack = nBlack;
  int color[nNodes];
  for (counter = 0; counter < nNodes; counter++)
    color[counter] = prevColor[counter];

  int nextNode;  
  color[nodeNumber] = 1;
  nBlack++;

  int found = 0;
  if (propagate (nodeNumber, color)) {
    for (counter = nodeNumber + 1; !found && counter < nNodes; counter++)
      if (color[counter] < 0) {
	nextNode = counter;
	found = 1;
      }
    if (found)
      backtrack(nextNode, color);
    else 
      process_solution(color);
  }

  nBlack = prevNBlack;
  for (counter = 0; counter < nNodes; counter++)
    color[counter] = prevColor[counter];
  color[nodeNumber] = 0;

  if (propagate (nodeNumber, color)) {
    found = 0;
    for (counter = nodeNumber + 1; !found && counter < nNodes; counter++)
      if (color[counter] < 0) {
	nextNode = counter;
	found = 1;
      }
    if (found)
      backtrack(nextNode, color);
    else 
      process_solution(color);
  }
}

int propagate (int nodeNumber, int color[]) {
  int success = 1;
  int propagated[nodeNumber];
  int nPropagated = 0;
  if (VR)
    printf("propagating for %d\n", nodeNumber);
  int counter;
  for (counter=0; success && counter < nNodes; counter++)
    if (edges[nodeNumber][counter]) {
      if (color[counter] >= 0) {
	if (color[nodeNumber] == 1 && color[counter] == 1)
	  success = 0;
      }
      else {
	color[counter] = 1-color[nodeNumber];
	propagated[nPropagated++] = counter;
	if (VR)
	  printf("setting %d to %d\n", counter, color[counter]);
	if (color[counter])
	  nBlack++;
      }
    }

  for (counter = 0; success && counter < nPropagated; counter++)
    success = propagate(propagated[counter], color);

  return success;
}


void process_solution(int color[]) {
  if (nBlack > best) {
    best = nBlack;
    if (VR)
      printf("best is now %d\n", best);
    int id = 0;
    int counter;
    for (counter=0; counter < nNodes; counter++)
      if (color[counter] == 1)
	bestBlack[id++] = counter;
  }
}
