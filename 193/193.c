#include <stdio.h>
#include <stdlib.h>
#pragma GCC diagnostic ignored "-Wunused-result"
#define VR 1

int edges[100][100];
int black[100];
int bestBlack[100];
int colored[100];
int nNodes;
int best;
int nColored;

void construct_candidates(int nodeNumber, int candidates[], int* nCandidates);
void propagate (int nodeNumber, int propagated[], int* nPropagated);
void undopropagation (int propagated[], int nPropagated);
void backtrack (int);

int main(void) {
  int numberOfCases;
  scanf ("%d", &numberOfCases);
  int caseCounter;
  for (caseCounter = 0; caseCounter < numberOfCases; caseCounter++)
    {
      int nEdges;
      scanf("%d %d\n", &nNodes, &nEdges);
      int edgeCounter;
      for (edgeCounter=0; edgeCounter < nEdges; edgeCounter++) {
	int first, second;
	scanf("%d %d\n", &first, &second);
	edges[first-1][second-1] = 1;
	edges[second-1][first-1] = 1;
      }
      int counter;
      for (counter=0; counter < nNodes; counter++) 
	black[counter] = 0;

      best = 0;
      nColored = 0;
      backtrack(0);

      printf("%d\n%d", best, bestBlack[0]+1);
      for (counter=1; counter < best; counter++)
	printf(" %d", bestBlack[counter]+1);
      printf("\n");
      
    }
  return 0;
}

void backtrack(int nodeNumber) {
  int counter;

  if (nodeNumber == nNodes) {
    if (nColored > best) {
      best = nColored;
      int id = 0;
      for (counter=0; counter < nNodes; counter++)
	if (black[counter])
	  bestBlack[id++] = counter;
    }
    return;
  }

  if (colored[nodeNumber])
    backtrack(nodeNumber+1);


  colored[nodeNumber] = 1;
  black[nodeNumber] = 1;
  nColored++;
  /*1 is black*/
  int propagated[nNodes];
  int nPropagated = 0;
  propagate (nodeNumber, propagated, &nPropagated);
  backtrack(nodeNumber+1);
  undopropagation (propagated, nPropagated);
  nColored--;

  black[nodeNumber] = 0;
  propagate (nodeNumber, propagated, &nPropagated);
  backtrack(nodeNumber+1);
  undopropagation (propagated, nPropagated);
  colored[nodeNumber] = 0;

}


void propagate (int nodeNumber, int propagated[], int* nPropagated) {
  int counter;
  for (counter=0; counter < nNodes; counter++)
    if (edges[nodeNumber][counter] && !colored[counter]) {
      black[counter] = 1-black[nodeNumber];
      if (black[counter])
	nColored++;
      colored[counter] = 1;
      propagated[*nPropagated] = counter;
      (*nPropagated)++;
      propagate (counter, propagated, nPropagated);
    }
}

void undopropagation (int propagated[], int nPropagated) {
  int counter;
  for (counter = 0; counter < nPropagated; counter++) {
    if (black[propagated[counter]])
      nColored--;
    colored[propagated[counter]] = 0;
  }
}
