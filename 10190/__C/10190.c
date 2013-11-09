#include <stdio.h>

void main(void){
  unsigned int first, second;
  while (scanf("%u %u" ,&first, &second) != EOF){
    int flag = 1;
    if (first < 2 || second < 2)
      flag = 0;
    else if (first % second != 0)
      flag = 0;

    unsigned int sequence [100];
    unsigned int index = 0;
    while (flag && (first > 1)){
      sequence[index++] = first;
      if (first % second != 0)
	flag = 0;
      first /= second;
      if (first >= sequence[index - 1])
	flag = 0;
    }

    if (!flag)
      printf("Boring!\n");
    else{
      int counter;
      for (counter = 0; counter < index; counter++)
	printf("%u ", sequence[counter]);
      printf("%u\n" , first);
    }
  }
}
