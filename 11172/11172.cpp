#include <iostream>

using std::endl;
using std::cout;
using std::cin;

int main(void) {
  int num_cases;
  cin >> num_cases;
  for (int case_counter = 0; case_counter < num_cases; case_counter++) {
    int num1, num2;
    cin >> num1 >> num2;
    if (num1 > num2)
      cout << '>';
    else if (num1 < num2)
      cout << '<';
    else
      cout << '=';
    cout << endl;
  }
  return 0;
}
