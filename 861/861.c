#include <stdio.h>
#include <stdlib.h>


typedef struct location_ {
  char row;
  char col;
} location;

/*TODO improve by single allocation for max input size*/

unsigned long int numSolutions;
char **places;

void backtrack(location*, int, int, int);
int is_solution (location*, int, int, int);
void process_solution (location*, int);
void construct_candidates (location*, int, int, int, location*, int*);
void markattack(location loc, int n);
void updateplaces (char** from , char** to, int n);
void printplaces(int);

int main (void) {
  places = (char**) malloc (sizeof(char*) * 8);
  int counter;
  for (counter = 0 ; counter < 8; counter++)
    *(places + counter) = (char*) malloc (sizeof(char) * 8);

  int n;
  int k;
  location partial[8];
  scanf ("%d %d", &n, &k);

  while (n >= 1) {
    numSolutions = 0;
    /*initialize chessboard*/
    int rowC,colC;
    for (rowC = 0; rowC < n; rowC++)
      for (colC=0; colC < n; colC++)
	places[rowC][colC] = 0;

    backtrack (partial, -1, n, k);
    printf ("%lu\n", numSolutions);
    scanf ("%d %d", &n, &k);
  }
  return 0;
}

void backtrack(location* partial, int position, int n, int k) {
  if (is_solution(partial, position, n, k))
    process_solution(partial, position);
  else {
    int nCandidates;
    location candidates[n*n];
    char **oldplaces = (char**) malloc (sizeof(char*) * n);
    int counter;
    for (counter = 0; counter < n; counter++)
      *(oldplaces+counter) = (char*) malloc (sizeof(char) * n);
    /*construct candidates for the next position*/
    construct_candidates (partial, position + 1, n, k, &candidates, &nCandidates);
    for (counter = 0; counter < nCandidates; counter++) {
      updateplaces(places, oldplaces, n);
      markattack(candidates[counter], n);
      partial [position + 1] = candidates[counter];
      backtrack (partial, position + 1, n, k);
      updateplaces (oldplaces, places, n);
    }
  }
}

int is_solution (location partial[], int position, int n, int k) {
  return (position == k-1);
}

void process_solution (location partial[], int position) {
  numSolutions ++;
}

void construct_candidates (location partial[], int position, int n, int k, location candidates[], int* nCandidates){

  *nCandidates = 0;

  /* use places here */
  int index = 0;
  int lastRow = partial[position - 1].row;
  int lastCol = partial[position - 1].col;
  /*Not elegant. Fix this!*/
  if (position == 0) {
    lastRow = 0;
    lastCol = -1;
  }

  int rowCounter, colCounter, prevCounter;
  rowCounter = lastRow;
  /*This partitioning also not elegant!*/
    for (colCounter = lastCol + 1; colCounter < n; colCounter++)
      if (!places[rowCounter][colCounter])
	{
	  candidates[index].row = rowCounter;
	  candidates[index].col = colCounter;
	  index++;
	  (*nCandidates) ++;
	}

  for (rowCounter = lastRow + 1; rowCounter < n; rowCounter++)
    for (colCounter = 0; colCounter < n; colCounter++)
      if (!places[rowCounter][colCounter])
	{
	  candidates[index].row = rowCounter;
	  candidates[index].col = colCounter;
	  index++;
	  (*nCandidates) ++;
	}

}

/* The problem is here, with the way that I
   have passed two-dimensional array */
void updateplaces (char** from , char** to, int n) {
  int c1, c2;
  for (c1 = 0; c1 < n; c1++)
    for (c2 = 0; c2 < n; c2++) {
      *(*(to+c1) + c2) = *(*(from+c1) + c2);
    }
}

void markattack(location loc, int n) {
  /* printf("before marking (%d,%d):\n", loc.row, loc.col); */
  /* printplaces(n); */
  int row = loc.row;
  int col = loc.col;

  int hor[] = {-1, 1};
  int ver[] = {-1, 1};
  int i, j;
  for (i = 0; i < 2; i++)
    for (j = 0; j < 2; j++)
      {
	int r = row;
	int c = col;
	while  (r>=0 && r<n && c>=0 && c<n) {
	  places [r][c] = 1;
	  r += hor[i];
	  c += ver[j];
	}
      }

  /* printf("after marking:\n"); */
  /* printplaces(n); */
}

void printplaces(int n)
{
  int counter;
  for (counter = 0; counter < n*3; counter++)
    printf("-");
  printf("\n");

  int i;
  int j;
  for (i = 0; i<n; i++){
    for (j = 0; j<n; j++)
	if (places[i][j])
	  printf("O |");
	else
	  printf("  |");
    printf ("\n");
    for (counter = 0; counter < n*3; counter++)
      printf("-");
    printf("\n");
  }
}
