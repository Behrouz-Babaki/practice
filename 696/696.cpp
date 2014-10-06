#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(void) {
  size_t num_rows, num_cols;
  cin >> num_rows >> num_cols;
  while (num_rows > 0 && num_cols > 0) {
    size_t num_pieces;
    if (num_cols == 0 || num_rows == 0)
      num_pieces = 0;
    if (num_cols == 1 || num_rows == 1)
      num_pieces = num_rows * num_cols;
    else if (num_cols == 2 || num_rows == 2){
      size_t total = num_rows *num_cols;
      if (total == 4)
	num_pieces = total;
      if (total == 6)
	num_pieces = 4;
      if (total >= 8)
	num_pieces = total/2;
    }

    else if (num_cols >= 3 && num_rows >= 3) {
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
