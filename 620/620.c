#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *inputString(FILE*, size_t);
int find_stage(char*, size_t, size_t);


int main(void) {
  char* names[4] = { "SIMPLE",
		     "FULLY-GROWN",
		     "MUTAGENIC",
		     "MUTANT"};

  size_t num_cases;
  scanf("%zd\n", &num_cases);
  size_t case_counter;
  for (case_counter = 0; case_counter < num_cases; case_counter++) {
    char* chain = inputString (stdin, 10);
    int stage = find_stage(chain, 0, (size_t) (strlen(chain)));
    printf("%s\n", names[stage]);
  }
  return 0;
}

/* from: [http://stackoverflow.com/a/16871702] */
char *inputString(FILE* fp, size_t size){
  /*The size is extended by the input with the value of the provisional*/
  char *str;
  int ch;
  size_t len = 0;
  str = realloc(NULL, sizeof(char)*size);/*size is start size*/
  if(!str)return str;
  while(EOF!=(ch=fgetc(fp)) && ch != '\n'){
    str[len++]=ch;
    if(len==size){
      str = realloc(str, sizeof(char)*(size+=16));
      if(!str)return str;
    }
  }
  str[len++]='\0';
  return realloc(str, sizeof(char)*len);
}

int find_stage(char* chain, size_t start, size_t end) {

  if (start == end)
    return 3;

  if (start == end - 1) {
    if (chain[start] == 'A')
      return 0;
    else
      return 3;
  }

  if (chain[end-1] == 'B' && chain[end-2] == 'A')
    if (find_stage(chain, start, end-2) < 3)
      return 1;
  
  if (chain[start] == 'B' && chain[end-1] == 'A')
    if (find_stage(chain, start + 1, end-1) < 3)
      return 2;

  return 3;
}
