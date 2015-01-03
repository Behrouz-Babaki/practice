#include <stdio.h>
#include <stdlib.h>

unsigned long long int numSolutions;
typedef int location;
int locations[8];
int bestSolution;

void backtrack(int*, int, int);
void construct_candidates (int*, int, int, int*, int*);

int main (void) {
  int counter;
  int caseCounter = 0;
  int result;
  int value;

  result = scanf ("%d ", &value);
  locations[0] = value - 1;
  while (result != EOF) {
    for (counter = 1; counter < 8; counter++) {
      int value ;
      result = scanf("%d ", &value);
      locations[counter] = value - 1;
    }
    
    bestSolution = 8;
    int partial[8];
    backtrack(partial, 0, -1);

    printf ("Case %d: %d\n", ++caseCounter, bestSolution);
    /* reading next case */
    result = scanf("%d", &value);
    locations[0] = value - 1;
  }
  return 0;
}

void backtrack(int* partial, int steps, int position) {
  if (position == 7 && steps < bestSolution)
    bestSolution = steps;
  else {
    int nCandidates;
    int candidates[8];
    int counter;
    int extraSteps = 0;
    /*construct candidates for the next position*/
    construct_candidates (partial, steps, position + 1, candidates, &nCandidates);
    /* printf("number of candidates:%d\n" , nCandidates); */
    for (counter = 0; counter < nCandidates; counter++) {
      partial [position + 1] = candidates[counter];
      if(candidates[counter] != locations[position + 1])
	extraSteps = 1;
      if (steps + extraSteps < bestSolution)
	backtrack (partial, steps + extraSteps, position + 1);
    }
  }
}


void construct_candidates (int partial[], int steps, int position, int candidates[], int* nCandidates){
  int index = 0;
  *nCandidates = 0;

  int origLocation = locations[position];
  int directions[] = {-1, 1};
  int counter;
  int dirCounter;

  for (counter = 0; counter < 8; counter++)
    for (dirCounter = 0; dirCounter < 2; dirCounter++) {
      int currentLocation = origLocation + counter * directions[dirCounter];
      if (currentLocation >= 0 && 
	  currentLocation < 8)
	{
	  int attack = 0;
	  int prevCounter;
	  for (prevCounter = 0; !attack && prevCounter < position; prevCounter++)
	    if (partial[prevCounter] == currentLocation ||
		prevCounter - position == partial[prevCounter] - currentLocation ||
		prevCounter - position == currentLocation - partial[prevCounter]) 
	      attack = 1;

	

	  if (!attack){
	    candidates[index++] = currentLocation;
	    (*nCandidates)++;
	  }
	}
    }
}

