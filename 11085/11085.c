#include <stdio.h>
#include <stdlib.h>


unsigned long long int numSolutions;
typedef int location;
int locations[8];
int bestSolution;

void backtrack(int*, int, int);
int is_solution (int*, int, int);
void process_solution (int*, int, int);
void construct_candidates (int*, int, int, int*, int*);

int main (void) {
  int counter;
  int caseCounter = 0;
  int result;

  result = scanf ("%d ", &locations[0]);
  while (result != EOF) {
    for (counter = 1; counter < 8; counter++)
      result = scanf("%d ", &locations[counter]);
    
    bestSolution = 64;
    int partial[8];
    backtrack(partial, 0, -1);

    printf ("Case %d: %d\n", caseCounter, bestSolution);
    /* reading next case */
    result = scanf("%d", &locations[0]);
  }
  return 0;
}

void backtrack(int* partial, int steps, int position) {
  if (is_solution(partial, steps, position))
    process_solution(partial, steps, position);
  else {
    int nCandidates;
    int candidates[8];
    int counter;
    int extraSteps;
    /*construct candidates for the next position*/
    construct_candidates (partial, steps, position + 1, candidates, &nCandidates);
    
    for (counter = 0; counter < nCandidates; counter++) {
      partial [position + 1] = candidates[counter];
      abs (candidates[counter] - locations[position + 1]);
      backtrack (partial, steps + extraSteps, position + 1);
    }
  }
}

int is_solution (int* partial, int steps, int position) {
  return (position == 7);
}

void process_solution (int partial[], int steps, int position) {
  if (steps < bestSolution)
    bestSolution = steps;
}

void construct_candidates (int partial[], int steps, int position, int candidates[], int* nCandidates){
  *nCandidates = 0;
}

