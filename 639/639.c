#include <stdio.h>

size_t max;
size_t current;

void print_board(int [4][4], size_t);
void recurse (int board[4][4], size_t board_size, size_t row, size_t col);
int safe (int board[4][4], size_t board_size, size_t row, size_t col);
void next_cell (int board[4][4], size_t row, size_t col, size_t board_size);

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
	  board[row_counter][col_counter] = 2; 
      }
      scanf("\n");
    }
    max = 0;
    current = 0;
    recurse (board, board_size, 0, 0);
    printf ("%zd\n", max);
    scanf ("%zd\n", &board_size);
  }
  return 0;
}

void recurse (int board[4][4], size_t board_size, size_t row, size_t col) {
  if (row == board_size) {
    if (current > max) 
      max = current;
    return;
  }

  // If there is a wall, go to the next cell
  if (board[row][col] == 2) 
    next_cell (board, row, col, board_size);
  else {
    board[row][col] = 0;
    next_cell (board, row, col, board_size);
    
    if (safe (board, board_size, row, col)) {
      board[row][col] = 1;
      current++;
      next_cell(board, row, col, board_size);
      board[row][col] = 0;
      current--;
    }
  }
}

int safe (int board[4][4], size_t board_size, size_t row, size_t col) {
  int hit = 0;
  int stop = 0;
  int row_counter, col_counter;
  for (col_counter = col-1; !stop && col_counter >=0; col_counter--)
    if (board [row][col_counter] == 1) {
      hit = 1;
      stop = 1;
    }
    else if (board[row][col_counter] == 2)
      stop = 1;

  stop = hit;
  for (col_counter = col+1; !stop && col_counter < board_size; col_counter++)
    if (board [row][col_counter] == 1) {
      hit = 1;
      stop = 1;
    }
    else if (board[row][col_counter] == 2)
      stop = 1;

  stop = hit;
  for (row_counter = row-1; !stop && row_counter >=0; row_counter--)
    if (board [row_counter][col] == 1) {
      hit = 1;
      stop = 1;
    }
    else if (board[row_counter][col] == 2)
      stop = 1;

  stop = hit;
  for (row_counter = row+1; !stop && row_counter < board_size; row_counter++)
    if (board [row_counter][col] == 1) {
      hit = 1;
      stop = 1;
    }
    else if (board[row_counter][col] == 2)
      stop = 1;

  return !hit;
}

void next_cell (int board[4][4], size_t row, size_t col, size_t board_size) {
    if (col < board_size)
      recurse (board, board_size, row, col+1);
    else 
      recurse (board, board_size, row+1, 0);
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
