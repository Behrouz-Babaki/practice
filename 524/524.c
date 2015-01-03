#include <stdio.h>
#include <stdlib.h>

int primes[] = {2,3,5,7,11,13,17,19,23,29,31};
int nPrimes = 11;
int partial[16];
int n;
int caseNumber;

void backtrack (int[], int);
void construct_candidates (int[] , int, int[], int*);
int isSumPrime (int sum);

int main(void) {
  int result;
  int counter;
  int firstline = 1;
  caseNumber = 0;
  result = scanf ("%d\n", &n);
  while (result != EOF)
    {
      caseNumber++;
      partial[0] = 1;
      if (firstline) 
	firstline = 0;
      else
	printf("\n");
      printf("Case %d:\n", caseNumber);
      backtrack(partial, 0);
      result = scanf ("%d\n", &n);
    }
  return 0;
}

void backtrack (int partial[], int position) {
  int counter;
  if (position == n-1) {
    if (isSumPrime(partial[position] + partial[0])){
      printf("%d", partial[0]);
	for (counter = 1; counter < n; counter++)
	  printf(" %d", partial[counter]);
	printf("\n");
      }
  }
  
  else {
    int candidates[n];
    int nCandidates;
    construct_candidates (partial, position+1, candidates, &nCandidates);
    for (counter = 0; counter < nCandidates; counter++) {
      partial[position+1] = candidates[counter];
      backtrack(partial, position+1);
    }
  }
}

void construct_candidates (int partial[] , int position, int candidates[], int* nCandidates) {
  *nCandidates = 0;
  int candId = 0;
  int counter;
  for (counter = 2; counter <= n; counter++) {
    int used = 0;
    int usedCounter;
    for (usedCounter=0; !used && usedCounter < position; usedCounter++)
      if (partial[usedCounter] == counter) 
	used = 1;
    
    if (!used) {
      if (isSumPrime(counter+partial[position-1])) {
	(*nCandidates)++;
	candidates[candId++] = counter;
      }
    }
  }
}


int isSumPrime (int sum) {
  int sumPrime = 0;
  int primeCounter;
  for (primeCounter = 0; !sumPrime && primeCounter < nPrimes; primeCounter++)
    if (primes[primeCounter] == sum)
      sumPrime = 1;
  return sumPrime;
}
