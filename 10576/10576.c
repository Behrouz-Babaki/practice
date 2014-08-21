#include <stdio.h>
#include <stdlib.h>

long int best;
long int s, d;

void backtrack(int*, int, long int, long int);
void construct_candidates (int*, int, int*, int*);

int main (void) {

  int result = scanf("%ld %ld\n", &s, &d);
  while (result != EOF) {
    best = -12 * d - 1;
    int partial[12];
    backtrack(partial, -1, 0, 0);
    if (best > 0)
      printf("%ld\n", best);
    else
      printf("Deficit\n");

    result = scanf("%ld %ld\n", &s, &d);
  }
  return 0;
}

void backtrack(int* partial, int position, long int gain, long int gain5) {

  if (position== 11) {
    if (gain > best)
    best = gain;
  }
  else {
    int nCandidates;
    int candidates[2];
    int counter;
    long int oldGain, oldGain5;
    /*construct candidates for the next position*/
    construct_candidates (partial, position+1, candidates, &nCandidates);
    /* printf("number of candidates:%d\n" , nCandidates); */
    for (counter = 0; counter < nCandidates; counter++) {
      oldGain5 = gain5;
      oldGain = gain;
      if (candidates[counter])
	gain += s;
      else
	gain -= d;
      if (position + 1 == 4) 
	gain5 = gain;
      if (position + 1 > 4) {
	if (partial[position-4] == 1)
	  gain5 -= s;
	else
	  gain5 += d;

	if (candidates[counter]) 
	  gain5 += s;
	else 
	  gain5 -= d;
      }
      if (position + 1 < 4 ||
	  gain5 < 0) {
	partial [position+1] = candidates[counter];
	backtrack (partial, position + 1, gain, gain5);
      }
      gain = oldGain;
    gain5 = oldGain5;
    }
  }
}


void construct_candidates (int partial[], int position, int candidates[], int* nCandidates){
  candidates[0] = 0;
  candidates[1] = 1;
  *nCandidates = 2;
}

