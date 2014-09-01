#include <stdio.h>

size_t pixels(char*, char*);
void fill_array (int array[32][32],
		 char*, size_t*, 
		 size_t, size_t, 
		 size_t, size_t);

int main(void){
  size_t num_cases;
  scanf("%zd\n" , &num_cases);
  int case_counter;
  for (case_counter = 0; case_counter < num_cases; case_counter++) {
    char line1[4100], line2[4100];
    scanf("%s\n", line1);
    scanf("%s\n", line2);
    printf("There are %zd black pixels.\n", pixels(line1,line2));
  }
  return 0;
}

size_t pixels(char* qt1, char* qt2) {

  int a1[32][32];
  int a2[32][32]; 

  size_t pos = 0;
  fill_array(a1, qt1, &pos, 0, 32, 0, 32);
  pos = 0;
  fill_array(a2, qt2, &pos, 0, 32, 0, 32);

  size_t num_black = 0;
  size_t x_counter;
  size_t y_counter;
  for (x_counter = 0; x_counter < 32; x_counter++)
    for (y_counter = 0; y_counter < 32; y_counter++)
      if (a1[x_counter][y_counter] || a2[x_counter][y_counter])
	num_black++;
  return num_black;
}

void fill_array (int array[32][32], char* qt, size_t* pos, 
		 size_t x_start, size_t x_end, 
		 size_t y_start, size_t y_end) {
  char node = qt[*pos];
  (*pos)++;
  
  if (node == 'e' || node == 'f') {
    int value = (node == 'f');
    size_t x_counter, y_counter;
    for (x_counter = x_start; x_counter < x_end; x_counter++)
      for (y_counter = y_start; y_counter < y_end; y_counter++)
	array[x_counter][y_counter] = value;
    return;
  }

  size_t x_mid = (x_start + x_end) / 2;
  size_t y_mid = (y_start + y_end) / 2;
  fill_array (array, qt, pos, x_start, x_mid, y_mid, y_end);
  fill_array (array, qt, pos, x_start, x_mid, y_start, y_mid);
  fill_array (array, qt, pos, x_mid, x_end, y_start, y_mid);
  fill_array (array, qt, pos, x_mid, x_end, y_mid, y_end);

}

