#include <iostream>
#include <vector>
#include <utility>

using std::endl;
using std::cin;
using std::cout;
using std::vector;
using std::ws;
using std::pair;
using std::make_pair;

enum piece_type {Rook, Knight, Queen, King};
size_t best_solution;

void backtrack (vector<vector<bool> > board, size_t num_pieces, piece_type pt);
void put_candidate (vector<vector<bool> >& board, piece_type pt, size_t row, size_t col);
void put_rook (vector<vector<bool> >& board, size_t row, size_t col);
void put_king (vector<vector<bool> >& board, size_t row, size_t col);
void put_queen (vector<vector<bool> >& board, size_t row, size_t col);
void put_knight (vector<vector<bool> >& board, size_t row, size_t col);

int main(void) {
  size_t number_of_cases;
  cin >> number_of_cases >> ws;
  for (size_t case_counter = 0; case_counter < number_of_cases; case_counter++) {
    char piece;
    cin >> piece;
    piece_type current_piece_type;
    switch (piece) {
    case 'r':
      current_piece_type = Rook;
      break;
    case 'k':
      current_piece_type = Knight;
      break;
    case 'Q':
      current_piece_type = Queen;
      break;
    case 'K':
      current_piece_type = King;
      break;
    }
    size_t num_rows, num_cols;
    cin >> num_rows >> num_cols >> ws;
    best_solution = 0;
    vector<vector<bool> > board (num_rows, vector<bool> (num_cols, true));
    backtrack (board, 0, current_piece_type);
    cout << best_solution << endl;
  }
  return 0;
}

void backtrack (vector<vector<bool> > board, size_t num_pieces, piece_type pt) {
  cout << "entered" << endl;
  size_t num_rows = board.size();
  size_t num_cols = board[0].size();
  vector<pair<size_t, size_t> > candidate_positions;
  for (size_t row_counter = 0; row_counter < num_rows; row_counter++)
    for (size_t col_counter = 0; col_counter < num_cols; col_counter++)
      if (board[row_counter][col_counter])
	candidate_positions.push_back(make_pair(row_counter, col_counter));

  if (candidate_positions.size() == 0) {
    if (num_pieces > best_solution)
      best_solution = num_pieces;
    return;
  }
  else
    for (auto candidate_position : candidate_positions) {
      vector<vector<bool> > next_board (board);
      put_candidate (next_board, pt, candidate_position.first, candidate_position.second);
      backtrack (next_board, num_pieces + 1, pt);
    }
}

void put_candidate (vector<vector<bool> >& board, piece_type pt, size_t row, size_t col) {
  switch(pt) {
  case Rook:
    put_rook (board, row, col);
    break;
  case King:
    put_king (board, row, col);
    break;
  case Queen:
    put_queen (board, row, col);
    break;
  case Knight:
    put_knight (board, row, col);
    break;
  }
}

void put_knight (vector<vector<bool> >& board, size_t row, size_t col) {
  board[row][col] = false;
  int x[] = {1, 1, 2, 2, -1, -1, -2, -2};
  int y[] = {2, -2, 1, -1, 2, -2, 1, -1};
  for (size_t case_cnt = 0; case_cnt < 8; case_cnt++) {
    size_t target_row = row + y[case_cnt];
    if (target_row >= 0 && target_row < board.size()) {
      size_t target_col = col + x[case_cnt];
      if (target_col >= 0 && target_col < board[0].size()) {
	board[target_row][target_col] = false;
      }
    }
  }
}
    
void put_king (vector<vector<bool> >& board, size_t row, size_t col) {
  for (size_t x = -1 ; x <= 1; x++)
    for (size_t y = -1; y <= 1; y++){
      size_t target_row = row + y;
      if (target_row >= 0 && target_row < board.size()) {
	size_t target_col = col + x;
	if (target_col >= 0 && target_col < board[0].size()) 
	  board[target_row][target_col] = false;
      }
    }
}

void put_queen (vector<vector<bool> >& board, size_t row, size_t col) {
  int x[] = {-1, 1};
  int y[] = {-1, 1};
  for (size_t y_inc = 0; y_inc < 2; y_inc++) {
    size_t target_row = row + y[y_inc];
    if (target_row >= 0 && target_row < board.size()) {
      for (size_t x_inc = 0; x_inc < 2; x_inc++){
	size_t target_col = col + x[x_inc];
	if (target_col >= 0 && target_col < board[0].size())
	  board[target_row][target_col] = false;
      }
    }
  }
}

void put_rook (vector<vector<bool> >& board, size_t row, size_t col) {
  int x[] = {-1, 1};
  int y[] = {-1, 1};
  for (size_t y_inc = 0; y_inc < 2; y_inc++) {
    size_t target_row = row + y[y_inc];
    while (target_row >= 0 && target_row < board.size()) {
      board[target_row][col] = false;
      target_row += y[y_inc];
    }
  }

  for (size_t x_inc = 0; x_inc < 2; x_inc++) {
    size_t target_col = col + x[x_inc];
    while (target_col >= 0 && target_col < board[0].size()) {
	  board[row][target_col] = false;
	  target_col += x[x_inc];
    }
  }
}

