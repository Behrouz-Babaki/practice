#include <stdio.h>
#include <stdlib.h>
#pragma GCC diagnostic ignored "-Wunused-result"
#define VR 0

int edges[500][500];
int bestBlack[500];
int nNodes;
int best;
int nBlack;

void propagate (int nodeNumber, int color[]);
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

      int counter;
      int inner;
      for (counter=0; counter < nNodes; counter++) 
	for (inner = 0; inner < nNodes; inner++)
	  edges[counter][inner] = 0;

      int edgeCounter;
      for (edgeCounter=0; edgeCounter < nEdges; edgeCounter++) {
	int first, second;
	scanf("%d %d", &first, &second);
	edges[first-1][second-1] = 1;
	edges[second-1][first-1] = 1;
      }

      int color[500];
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
  int* color = (int*) malloc (nNodes * sizeof(int));
  for (counter = 0; counter < nNodes; counter++)
    color[counter] = prevColor[counter];

  int nextNode;  
  color[nodeNumber] = 1;
  nBlack++;

  int found = 0;
  propagate (nodeNumber, color);
  if (VR)
    printf ("after prop: nBlack=%d best=%d\n", nBlack, best);
  for (counter = nodeNumber + 1; !found && counter < nNodes; counter++)
    if (color[counter] < 0) {
      nextNode = counter;
      found = 1;
    }
  if (found)
    backtrack(nextNode, color);
  else 
    process_solution(color);
  
  /* white nodes do not need propagation */
  nBlack--;
  for (counter = 0; counter < nNodes; counter++)
    color[counter] = prevColor[counter];
  color[nodeNumber] = 0;
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

  free(color);
}

void propagate (int nodeNumber, int color[]) {
  if (VR)
    printf("propagating for %d\n", nodeNumber);
  int counter;
  for (counter=0; counter < nNodes; counter++)
    if (edges[nodeNumber][counter] && color[counter] < 0) 
      color[counter] = 0;
}


void process_solution(int color[]) {
  if (nBlack > best) {
    best = nBlack;
    int id = 0;
    int counter;
    for (counter=0; counter < nNodes; counter++)
      if (color[counter] == 1)
	bestBlack[id++] = counter;
  }
}
