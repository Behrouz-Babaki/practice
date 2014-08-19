#include <stdio.h>
#include <stdlib.h>


struct location_ {
  char row;
  char col;
};

//TODO improve by single allocation for max input size

typedef struct location_ location;
unsigned long int numSolutions;

void backtrack(location*, int, int, int);
int is_solution (location*, int, int, int);
void process_solution (location*, int);
void construct_candidates (location*, int, int, int, location**, int*);
void print_partial (location*, int);

int main (void) {

  int n;
  int k;
  scanf ("%d %d", &n, &k);
  while (n >= 1) {
    location* partial = (location*) malloc(k*sizeof(location));
    if (partial == NULL)
      exit(1);

    numSolutions = 0;
    backtrack (partial, -1, n, k);
    printf ("%lu\n", numSolutions);
    free (partial);
    scanf ("%d %d", &n, &k);
  }
  return 0;
}

void backtrack(location* partial, int position, int n, int k) {
  print_partial (partial, position);
  if (is_solution(partial, position, n, k))
    process_solution(partial, position);
  else {
    int nCandidates;
    location** candidates = (location**) malloc(sizeof(location**));
    //construct candidates for the next position
    construct_candidates (partial, position + 1, n, k, candidates, &nCandidates);
    int counter;
    for (counter = 0; counter < nCandidates; counter++) {
      partial [position + 1] = (*candidates)[counter];
      backtrack (partial, position + 1, n, k);
    }
    free (*candidates);
    free (candidates);
  }
}

int is_solution (location partial[], int position, int n, int k) {
  return (position == k-1);
}

void process_solution (location partial[], int position) {
  printf ("^***\n");
  numSolutions ++;
}

void construct_candidates (location partial[], int position, int n, int k, location** candidates, int* nCandidates){
  *candidates = (location *) malloc ((n*n -position)*sizeof(location));
  *nCandidates = 0;

  int index = 0;
  int lastRow = partial[position - 1].row;
  int lastCol = partial[position - 1].col;
  if (position == 0) {
    lastRow = 0;
    lastCol = -1;
  }
    

  int rowCounter, colCounter, prevCounter;
  rowCounter = lastRow;
    for (colCounter = lastCol + 1; colCounter < n; colCounter++)
      {
	printf("trying (%d,%d)", rowCounter, colCounter);
	char attack = 0;
	for (prevCounter = 0; !attack && prevCounter < position; prevCounter++) {
	  char prevRow = partial[prevCounter].row;
	  char prevCol = partial[prevCounter].col;
	  if (((rowCounter == prevRow) && (colCounter == prevCol)) ||
	      (rowCounter - prevRow) == (colCounter - prevCol) ||
	      (rowCounter - prevRow) == -(colCounter - prevCol)) {	      
	    printf (" -> attacked by (%d,%d)\n", prevRow, prevCol);
	    attack = 1;
	  }
	}

	if (!attack) {
	  printf (" -> success\n");
	  (*candidates)[index].row = rowCounter;
	  (*candidates)[index].col = colCounter;
	  index++;
	  (*nCandidates) ++;
	}
      }
  
  for (rowCounter = lastRow + 1; rowCounter < n; rowCounter++)
    for (colCounter = 0; colCounter < n; colCounter++)
      {
	printf("trying (%d,%d)", rowCounter, colCounter);
	char attack = 0;
	for (prevCounter = 0; !attack && prevCounter < position; prevCounter++) {
	  char prevRow = partial[prevCounter].row;
	  char prevCol = partial[prevCounter].col;
	  if (((rowCounter == prevRow) && (colCounter == prevCol)) ||
	      (rowCounter - prevRow) == (colCounter - prevCol) ||
	      (rowCounter - prevRow) == -(colCounter - prevCol)) {	      
	    printf (" -> attacked by (%d,%d)\n", prevRow, prevCol);
	    attack = 1;
	  }
	}

	if (!attack) {
	  printf (" -> success\n");
	  (*candidates)[index].row = rowCounter;
	  (*candidates)[index].col = colCounter;
	  index++;
	  (*nCandidates) ++;
	}
      }
}

void print_partial (location* partial, int position) {
  int counter; 
  for (counter = 0; counter <= position; counter++)
    printf("(%d,%d) ", partial[counter].row, partial[counter].col);
  printf("\n");
}
