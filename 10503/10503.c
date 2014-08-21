#include <stdio.h>
#include <stdlib.h>
#pragma GCC diagnostic ignored "-Wunused-result"

int n;
int m;
int heads[14];
int tails[14];
int used [14];
int fHead, fTail, lHead, lTail;
int found;

void backtrack(int tail, int position);
void construct_candidates (int tail, int position, int candidates[], int sides[], int* nCandidates);

int main(void) {
  scanf("%d\n", &n);
  while (n) {
    scanf("%d\n", &m);
    scanf("%d %d\n", &fHead, &fTail);
    scanf("%d %d\n", &lHead, &lTail);
    int counter;
    for (counter = 0; counter < m; counter++)
      scanf("%d %d\n", &heads[counter], &tails[counter]);
    found = 0;
    backtrack(fTail, -1);
    if (found)
      printf("YES\n");
    else
      printf("NO\n");
    scanf("%d\n", &n);
  }
  return 0;
}

void backtrack(int tail, int position) {
  if (position == n-1)
    found = 1;
  else if (!found) {
    int nCandidates;
    int candidates[14];
    int sides[14];
    construct_candidates (tail, position + 1, candidates, sides, &nCandidates);
    int counter;
    for (counter = 0; !found && counter < nCandidates; counter++) {
      int nextTail;
      if (sides[counter])
	nextTail = tails[candidates[counter]];
      else
	nextTail = heads[candidates[counter]];
      used[candidates[counter]] = 1;
      backtrack (nextTail, position + 1);
      used[candidates[counter]] = 0;
    }
  }
}

void construct_candidates (int tail, int position, int candidates[], int sides[], int* nCandidates){
  *nCandidates = 0;
  int candId = 0;
  int counter;
  for (counter = 0; counter < m; counter++)
    {
      if (!used[counter]) {
	if (heads[counter] == tail &&
	    (position != (n-1) || tails[counter] == lHead)) {
	  candidates[candId] = counter;
	  sides[candId] = 1;
	  candId++;
	  (*nCandidates)++;
	}
	else if (tails[counter] == tail &&
	    (position != (n-1) || heads[counter] == lHead)) {
	  candidates[candId] = counter;
	  sides[candId] = 0;
	  candId++;
	  (*nCandidates)++;
	}
      }
    }
}
