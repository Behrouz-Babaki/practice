#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::min;
using std::max;

int main(void) {
  size_t num_rows, num_cols;
  cin >> num_rows >> num_cols;
  while (num_rows > 0 || num_cols > 0) {
    size_t lower, higher;
    lower = min(num_rows, num_cols);
    higher = max(num_rows, num_cols);

    size_t num_pieces;
    if (lower <= 1)
      num_pieces = num_rows * num_cols;
    else if (lower == 2){
      size_t blocks = higher / 4;
      size_t remainder = higher % 4;
      size_t extra;
      switch (remainder) {
      case 0:
	extra = 0;
	break;
      case 1:
	extra = 2;
	break;
      case 2:
	extra = 4;
	break;
      case 3:
	extra = 4;
	break;
      }
      num_pieces = blocks * 4 + extra;
    }
    else /*if (num_cols >= 3 && num_rows >= 3)*/ {
      size_t total = num_cols * num_rows;
      if (total % 2)
	total++;
      num_pieces = total / 2;
    }

    cout << num_pieces << " knights may be placed on a " << num_rows << 
      " row " << num_cols << " column board." << endl;
    cin >> num_rows >> num_cols;
  }
  return 0;
}
