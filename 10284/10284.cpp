#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

enum square_t {safe, attacked, black_pawn, white_pawn, black_knight, white_knight, black_queen, white_queen, black_rook, white_rook, black_king, white_king, black_bishop, white_bishop};

int main(void) {
  string line;
  while (getline(cin, line)){
    int index1 = 0, index2;
    vector<string> pieces;
    while (index1 < line.length()) {
      index2 = 0;
      while (line[index1+index2] != '/' && (index1+index2) != line.length())
	index2++;
      pieces.push_back(line.substr(index1,index2));
      index1 = index1+index2+1;
    }
    if (pieces.size() != 8) {
      cout << 0 << endl;
      break;
    }
    square_t board[8][8];
    for (int row_cnt = 0; row_cnt < 8; row_cnt++) {
      int col_cnt = 0;
      for (string::iterator itr = pieces[row_cnt].begin(); itr != pieces[row_cnt].end(); itr++){
	if (*itr >= '1' && *itr <= '8') {
	  int steps;
	  for (steps = 0 ;steps < (int)(*itr) - 48; steps++)
	    board[row_cnt][col_cnt+steps] = safe;
	  col_cnt += steps;
	}
	else{
	  switch(*itr) {
	  case 'p':
	    board[row_cnt][col_cnt] = black_pawn;
	    break;
	  case 'P':
	    board[row_cnt][col_cnt] = white_pawn;
	    break;
	  case 'r':
	    board[row_cnt][col_cnt] = black_rook;
	    break;
	  case 'R':
	    board[row_cnt][col_cnt] = white_rook;
	    break;
	  case 'n':
	    board[row_cnt][col_cnt] = black_knight;
	    break;
	  case 'N':
	    board[row_cnt][col_cnt] = white_knight;
	    break;
	  case 'q':
	    board[row_cnt][col_cnt] = black_queen;
	    break;
	  case 'Q':
	    board[row_cnt][col_cnt] = white_queen;
	    break;
	  case 'k':
	    board[row_cnt][col_cnt] = black_king;
	    break;
	  case 'K':
	    board[row_cnt][col_cnt] = white_king;
	    break;
	  case 'b':
	    board[row_cnt][col_cnt] = black_bishop;
	    break;
	  case 'B':
	    board[row_cnt][col_cnt] = white_bishop;
	    break;
	  }
	  col_cnt++;
	}
      }
    }
	  int q_row_incs[3] = {0, 1, -1};
	  int q_col_incs[3] = {0, 1, -1};
	  int r_row_incs[4] = {0, 0, 1, -1};
	  int r_col_incs[4] = {1, -1, 0, 0};
	  int b_row_incs[4] = {-1, 1, -1, 1};
	  int b_col_incs[4] = {1, -1, -1, 1};
	  int n_row_incs[8] = {2, 2, -2, -2, 1, 1, -1, -1};
	  int n_col_incs[8] = {1, -1, 1, -1, 2, -2, 2, -2};



    for (int row_cnt = 0; row_cnt < 8; row_cnt++) 
      for (int col_cnt = 0; col_cnt < 8; col_cnt++){
	if (board[row_cnt][col_cnt] == safe ||
	    board[row_cnt][col_cnt] == attacked)
	  continue;
	
	switch(board[row_cnt][col_cnt]) {
	case black_pawn:
	  if (row_cnt < 7 && col_cnt > 0 && board[row_cnt+1][col_cnt-1] == safe)
	    board[row_cnt+1][col_cnt-1] = attacked;
	  if (row_cnt < 7 && col_cnt < 7 && board[row_cnt+1][col_cnt+1] == safe)
	    board[row_cnt+1][col_cnt+1] = attacked;
	  break;
	case white_pawn:
	  if (row_cnt > 0 && col_cnt > 0 && board[row_cnt-1][col_cnt-1] == safe)
	    board[row_cnt-1][col_cnt-1] = attacked;
	  if (row_cnt > 0 && col_cnt < 7 && board[row_cnt-1][col_cnt+1] == safe)
	    board[row_cnt-1][col_cnt+1] = attacked;
	  break;
	case black_queen:
	case white_queen:
	  for (int row_inc_id = 0; row_inc_id < 3; row_inc_id++)
	    for (int col_inc_id = 0; col_inc_id < 3; col_inc_id++) {
	      int q_row_inc = q_row_incs[row_inc_id];
	      int q_col_inc = q_col_incs[col_inc_id];
	      if (!q_row_inc && !q_col_inc)
		continue;
	      int q_next_row = row_cnt + q_row_inc;
	      int q_next_col = col_cnt + q_col_inc;
	      while (q_next_row >= 0 && q_next_row < 8 
		     && q_next_col >= 0 && q_next_col < 8 
		     && (board[q_next_row][q_next_col] == safe 
			 || board[q_next_row][q_next_col] == attacked)) {
		board[q_next_row][q_next_col] = attacked;
		q_next_row += q_row_inc;
		q_next_col += q_col_inc;
	      }
	    }
	  break;
	case black_rook:
	case white_rook:
	  for (int inc_id = 0; inc_id < 4; inc_id++){
	      int r_row_inc = r_row_incs[inc_id];
	      int r_col_inc = r_col_incs[inc_id];
	      int r_next_row = row_cnt + r_row_inc;
	      int r_next_col = col_cnt + r_col_inc;
	      while (r_next_row >= 0 && r_next_row < 8 
		     && r_next_col >= 0 && r_next_col < 8 
		     && (board[r_next_row][r_next_col] == safe 
			 || board[r_next_row][r_next_col] == attacked)) {
		board[r_next_row][r_next_col] = attacked;
		r_next_row += r_row_inc;
		r_next_col += r_col_inc;
	      }
	    }
	  break;
	case black_bishop:
	case white_bishop:
	  for (int inc_id = 0; inc_id < 4; inc_id++){
	      int b_row_inc = b_row_incs[inc_id];
	      int b_col_inc = b_col_incs[inc_id];
	      int b_next_row = row_cnt + b_row_inc;
	      int b_next_col = col_cnt + b_col_inc;
	      while (b_next_row >= 0 && b_next_row < 8 
		     && b_next_col >= 0 && b_next_col < 8 
		     && (board[b_next_row][b_next_col] == safe 
			 || board[b_next_row][b_next_col] == attacked)) {
		board[b_next_row][b_next_col] = attacked;
		b_next_row += b_row_inc;
		b_next_col += b_col_inc;
	      }
	    }
	  break;
	case black_king:
	case white_king:
	  for (int row_inc_id = 0; row_inc_id < 3; row_inc_id++)
	    for (int col_inc_id = 0; col_inc_id < 3; col_inc_id++) {
	      int q_row_inc = q_row_incs[row_inc_id];
	      int q_col_inc = q_col_incs[col_inc_id];
	      if (!q_row_inc && !q_col_inc)
		continue;
	      int q_next_row = row_cnt + q_row_inc;
	      int q_next_col = col_cnt + q_col_inc;
	      if (q_next_row >= 0 && q_next_row < 8 
		     && q_next_col >= 0 && q_next_col < 8 
		     && (board[q_next_row][q_next_col] == safe 
			 || board[q_next_row][q_next_col] == attacked))
		board[q_next_row][q_next_col] = attacked;
	    }
	  break;
	case black_knight:
	case white_knight:
	  for (int inc_id = 0; inc_id < 8; inc_id++){
	      int n_row_inc = n_row_incs[inc_id];
	      int n_col_inc = n_col_incs[inc_id];
	      int n_next_row = row_cnt + n_row_inc;
	      int n_next_col = col_cnt + n_col_inc;
	      if (n_next_row >= 0 && n_next_row < 8 
		     && n_next_col >= 0 && n_next_col < 8 
		     && (board[n_next_row][n_next_col] == safe 
			 || board[n_next_row][n_next_col] == attacked)) 
		board[n_next_row][n_next_col] = attacked;
	    }
	  break;
	}
    }
    int safe_cnt = 0;
    for (int row_cnt = 0; row_cnt < 8; row_cnt++)
      for (int col_cnt = 0; col_cnt < 8; col_cnt++)
	if (board[row_cnt][col_cnt] == safe) {
	  safe_cnt++;
	}
    cout << safe_cnt << endl;

  }
  return 0;
}
