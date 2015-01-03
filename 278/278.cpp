#include <iostream>
#include <algorithm>

using std::endl;
using std::cin;
using std::ws;
using std::cout;
using std::min;

int main(void) {
  size_t number_of_cases;
  cin >> number_of_cases >> ws;
  for (size_t case_counter = 0; case_counter < number_of_cases; case_counter++) {
    char piece;
    cin >> piece;
    size_t num_rows, num_cols;
    cin >> num_rows >> num_cols >> ws;
    size_t num_pieces;
    size_t total, half_rows;
    switch (piece) {
    case 'r':
    case 'Q':
      num_pieces = min(num_rows, num_cols);
      break;
    case 'k':
      total = num_cols * num_rows;
      if (total % 2)
	total++;
      num_pieces = total / 2;
      break;
    case 'K':
      half_rows = num_rows / 2;
      if (num_rows % 2)
	half_rows++;
      total = num_cols * half_rows;
      if (total % 2)
	total++;
      num_pieces = total / 2;
      break;
    }
    cout << num_pieces << endl;
  }
  return 0;
}

