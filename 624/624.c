#include <stdio.h>
#include <stdlib.h>

int tapeLength;
int durations[20];
int best, bestCount;
int bestSol[20];
int numTracks;

void backtrack(int partial[], int position, int remaining);
int is_solution (int partial[], int position, int remaining);

int main(void) {
  int result;
  char line[1024];
  while (fgets(line, sizeof(line), stdin)) {
    int counter;
    char *p, *e;
    long int v;
    tapeLength = strtol (line, &e, 10);
    p = e;
    numTracks = strtol (p, &e, 10);
    for (p = e, counter = 0; counter < numTracks; p = e,counter++) {
      v = strtol(p, &e, 10);
      durations[counter] = v;
    }

    best = tapeLength;
    int partial [20];
    backtrack(partial, -1, tapeLength);
    
    int sum = 0;
    for (counter = 0; counter < bestCount; counter++)
      if(bestSol[counter]){
	printf("%d ", durations[counter]);
	sum += durations[counter];
      }
    printf("sum:%d\n", sum);
  }
  return 0;
}

void backtrack(int partial[], int position, int remaining) {

  int waste = is_solution(partial, position, remaining);
  if (waste >= 0) {
    if (waste < best) {
      best = waste;
      int counter;
      for (counter = 0; counter <= position; counter++)
	bestSol[counter] = partial[counter];
      bestCount = position+1;
    }
  }

  if (waste < 0) {
    /* include track */
    if (durations[position+1] <= remaining) {
      partial[position+1] = 1;
      backtrack(partial, position+1, remaining - durations[position+1]);
    }
    /* exclude track */
    partial[position+1] = 0;
    backtrack(partial, position+1, remaining);
  }
}


int is_solution (int partial[], int position, int remaining) {
  int counter;
  for (counter = position+1; counter < numTracks; counter++)
    if (durations[counter] <= remaining)
      return -1;
  return remaining;
}


