#include <stdio.h>
#include <stdlib.h>
#pragma GCC diagnostic ignored "-Wunused-result"

int n;
int m;
int heads[14];
int tails[14];
int fHead, fTail, lHead, lTail;

int main(void) {
  scanf("%d\n", &n);
  while (n) {
    scanf("%d\n", &m);
    scanf("%d %d\n", &fHead, &fTail);
    scanf("%d %d\n", &lHead, &lTail);
    int counter;
    for (counter = 0; counter < m; counter++)
      scanf("%d %d\n", &heads[counter], &tails[counter]);


    scanf("%d\n", &n);
  }
  return 0;
}
