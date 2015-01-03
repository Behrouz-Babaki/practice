#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main(void) {
  size_t num_cases;
  cin >> num_cases;
  for (size_t case_number = 1; case_number <= num_cases; case_number++) {
    int sum, diff;
    cin >> sum >> diff;
    size_t total = sum + diff;
    if (total % 2)
      cout << "impossible" << endl;
    else {
      int large, small;      
      large = total / 2;
      small = sum - large;
      if (large < 0 || small < 0)
	cout << "impossible" << endl;
      else
	cout << large << " " << small << endl;
    }
  }
  return 0;
}
