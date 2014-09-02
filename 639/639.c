#include <stdio.h>

size_t max;
size_t current;

void print_board(int [4][4], size_t);
int main(void) {

  size_t board_size;
  int board[4][4];

  scanf ("%zd\n", &board_size);
  while (board_size > 0) {
    size_t row_counter, col_counter;
    char ch;
    for (row_counter = 0; row_counter < board_size; row_counter++) {
      for (col_counter = 0; col_counter < board_size; col_counter++) {
	scanf ("%c", &ch);
	if (ch == '.')
	  board[row_counter][col_counter] = 0;
	else
	  board[row_counter][col_counter] = 1; 
      }
      scanf("\n");
    }
    size_t num_roks;
    max = 0;
    current = 0;
    num_roks = recurse (board, board_size, 0, 0);
    printf ("%zd\n", num_roks);
    scanf ("%d\n", &board_size);
  }
  return 0;
}

void recurse (int board[4][4], size_t board_size, size_t row, size_t col) {
  if (row == board_size)
    if (current > max) {
      max = current;
      return;
    }

  if (board[row][col] == 1) {
    if (col < board_size)
      recurse (board, board_size, row, col+1);
    else 
      recurse (board, board_size, row+1, 0);
  }
}

void print_board(int board[4][4], size_t board_size) {
    size_t row_counter, col_counter;
    for (row_counter = 0; row_counter < board_size; row_counter++) {
      for (col_counter = 0; col_counter < board_size; col_counter++)
	if (board[row_counter][col_counter])
	  printf("X");
	else
	  printf(".");

      printf("\n");
    }
}
