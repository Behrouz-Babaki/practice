#include <stdio.h>
#include <stdlib.h>


typedef struct location_ {
  char row;
  char col;
} location;

/*TODO improve by single allocation for max input size*/

unsigned long int numSolutions;
char **places;
int* ways;


void backtrack(location*, int, int, int);
int is_solution (location*, int, int, int);
void process_solution (location*, int);
void construct_candidates (location*, int, int, int, location*, int*);
void markattack(location loc, int n, location marked[], int* nMarked);
void revertmark(location marked[], int nMarked);
void updateplaces (char** from , char** to, int n);
void printplaces(int);

int main (void) {
  places = (char**) malloc (sizeof(char*) * 8);
  ways = (int*) malloc (sizeof(int) * 9);
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
	if ((rowC + colC) % 2 == 0)
	  places[rowC][colC] = 0;
	else
	  places[rowC][colC] = 1;

    *ways = 1;
    for (counter = 1; counter <= k; counter++)
      *(ways+counter) = 0;

    backtrack (partial, -1, n, k);

    int blackWays[9];
    for (counter =  0; counter <= 8; counter++)
      blackWays[counter] = ways[counter];

    for (rowC = 0; rowC < n; rowC++)
      for (colC=0; colC < n; colC++)
	if ((rowC + colC) % 2 == 0)
	  places[rowC][colC] = 1;
	else
	  places[rowC][colC] = 0;

    *ways = 1;
    for (counter = 1; counter <= k; counter++)
      *(ways+counter) = 0;

    backtrack (partial, -1, n, k);

    numSolutions = 0;

    for (counter = 0; counter <= k; counter++) {
      unsigned long int res = ways[counter] * blackWays[k-counter];
      numSolutions += res;
    }
    printf ("%lu\n", numSolutions);
    scanf ("%d %d", &n, &k);
  }
  return 0;
}

void backtrack(location* partial, int position, int n, int k) {
  if (is_solution(partial, position, n, k))
    process_solution(partial, position);
  else {
    int nCandidates, nmarked;
    location candidates[n*n];
    int counter;
    /*construct candidates for the next position*/
    construct_candidates (partial, position + 1, n, k, &candidates, &nCandidates);
    /* How many ways with this many bishops?*/
    ways[position+2] += nCandidates;
    for (counter = 0; counter < nCandidates; counter++) {
      location marked[64];      
      markattack(candidates[counter], n, marked, &nmarked);
      partial [position + 1] = candidates[counter];
      backtrack (partial, position + 1, n, k);
      revertmark(marked, nmarked);
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

void markattack(location loc, int n, location marked[], int* nMarked) {
  /* printf("before marking (%d,%d):\n", loc.row, loc.col); */
  /* printplaces(n); */
  int row = loc.row;
  int col = loc.col;
  int index = 0;

  int hor[] = {-1, 1};
  int ver[] = {-1, 1};
  int i, j;
  for (i = 0; i < 2; i++)
    for (j = 0; j < 2; j++)
      {
	int r = row;
	int c = col;
	while  (r>=0 && r<n && c>=0 && c<n) {
	  if (!places[r][c]) {
	    places [r][c] = 1;
	    location markedcell;
	    markedcell.row = r;
	    markedcell.col = c;
	    marked[index] = markedcell;
	    index ++;
	  }
	  r += hor[i];
	  c += ver[j];
	}
      }

  *nMarked = index;
  /* printf("after marking:\n"); */
  /* printplaces(n); */
}

void revertmark(location marked[], int nMarked) {
  int counter; 
  for (counter = 0; counter < nMarked; counter++)
      places[marked[counter].row][marked[counter].col] = 0;
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
