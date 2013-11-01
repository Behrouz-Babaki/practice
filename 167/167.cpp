//TODO The decision should be to find the column for each row
#include <cstdlib>
#include <iostream>
#include <utility>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::pair;

#define N 8

void printBoard (int**);
int bestScore (int**);
int rec (vector<pair<int, int> >, int**, int);

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
  vector<pair<int, int> > occupied;
  return rec (occupied, board, 0);
}

int rec (vector<pair<int, int> > occupied, int** board, int partialScore)
{

  if (occupied.size() == N)
    return partialScore;
  
  int bestScore = -1;
  /* Go through all cells of the board */
  for (int row = 0; row < N; row++){
     if (occupied.size() == 0)
        cout << "In row " << row << endl;
     if (occupied.size() == 1)
        cout << "     in row " << row << endl;
    for (int col = 0; col < N; col++)
      {
	bool isIllegal = false;
	/* Verify that it is legal to put a new queen here */
	for (auto itr = occupied.begin(), endItr = occupied.end(); !isIllegal && itr != endItr; itr++)
	  {
	    int r = itr->first, c = itr->second;
	    if (r == row || c == col || (r-row == c-col) || (r-row == col-c))
	      isIllegal = true;
	  }

	if (isIllegal)
	  continue;
	
	pair<int, int> newQueen (row,col);
	occupied.push_back(newQueen);
	int newpartialScore = partialScore + board[row][col];
	int score = rec(occupied, board, newpartialScore);
	occupied.pop_back();


	if (score > bestScore)
	  bestScore = score;
	
      }
  }
  return bestScore;
}
