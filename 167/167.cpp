#include <cstdlib>
#include <iostream>
#include <utility>
#include <vector>
#include <iomanip>

using std::cout;
using std::endl;
using std::cin;
using std::setw;
using std::vector;
using std::pair;

#define N 8

void printBoard (int**);
int bestScore (int**);
int rec (vector<int>, int**, int);

int main(void){
  int number_of_cases;
  cin >> number_of_cases;
  for (int counter = 0; counter < number_of_cases; counter++)
    {
      int **board;
      board = (int**) malloc (N*sizeof(*board));
      for (int row = 0; row < N; row++)
	{
	  int *current_row;
	  current_row = (int*) malloc (N*sizeof(*current_row));
	  for (int col = 0; col < N; col++)
	    cin >> current_row[col];

	  board[row] = current_row;
	}
      // printBoard(board);
      cout << setw(5);
      cout << bestScore (board) << endl;
    }
  return 0;
}

void printBoard (int ** board)
{
  for (int row = 0; row < N; row++)
    {
      for (int col = 0; col < N; col++)
	cout << board[row][col] << "\t";
      cout << endl;
    }
}

int bestScore (int** board)
{
  vector<int>  occupied;
  return rec (occupied, board, 0);
}

int rec (vector<int> occupied, int** board, int partialScore)
{

  if (occupied.size() == N)
    return partialScore;
  
  int bestScore = -1;
  int row = occupied.size();
  /* Go through all columns of this row */
    for (int col = 0; col < N; col++)
      {
         bool illegal = false;
	/* Verify that it is legal to put a new queen here */
        for (int r = 0; !illegal && r < row; r++){
           int c = occupied[r];
           if (r == row || c == col || (r-row == c-col) || (r-row == col-c))
	      illegal = true;
	}
        
        if (!illegal){
           occupied.push_back(col);
           int newpartialScore = partialScore + board[row][col];
           int score = rec(occupied, board, newpartialScore);
           occupied.pop_back();
           
           if (score > bestScore)
              bestScore = score;
        }
	
      }

  return bestScore;
}
