#include <stdio.h>
#include <stdlib.h>
#pragma GCC diagnostic ignored "-Wunused-result"

int edges[100][100];
int black[100];
int bestBlack[100];
int colored[100];
int nNodes;
int best;
int nColored;

void construct_candidates(int nodeNumber, int candidates[], int* nCandidates);
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
  int candidates[nNodes];
  int nCandidates;
  int counter;
  if (nodeNumber == nNodes)
    return;
  if (colored[nodeNumber])
    backtrack(nodeNumber+1);
  construct_candidates(nodeNumber, candidates, &nCandidates);
  if (nCandidates == 0) {
    if (nColored > best) {
      best = nColored;
      int id = 0;
      for (counter=0; counter < nNodes; counter++)
	if (black[counter])
	  bestBlack[id++] = counter;
    }
    return;
  }

  for (counter = 0; counter < nCandidates; counter++) {
    int currentNode = candidates[counter];
    colored[currentNode] = 1;
    black[currentNode] = 1;
    nColored++;
    int neighbours[nNodes];
    int nodeCounter;
    int nbrCounter = 0;
    for (nodeCounter = 0; nodeCounter < nNodes; nodeCounter++)
	if (edges[currentNode][nodeCounter] && !colored[nodeCounter]){
	  colored[nodeCounter] = 1;
	  neighbours[nbrCounter++] = nodeCounter;
	}
    backtrack(currentNode+1);
    for (nodeCounter=0; nodeCounter < nbrCounter; nodeCounter++) 
      colored[neighbours[nodeCounter]] = 0;
    colored[currentNode] = 0;
    black[currentNode] = 0;
    nColored--;
  }
}


void construct_candidates(int nodeNumber, int candidates[], int* nCandidates) {
  *nCandidates = 0;
  int counter;
  int id = 0;
  for (counter=0; counter < nNodes; counter++)
    if (edges[nodeNumber][counter] && !colored[nodeNumber]) {
      candidates[id++] = nodeNumber;
      (*nCandidates)++;
    }
}
