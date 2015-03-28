#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main(void) {
  int n, day, month, year;
  cin >> n >> day >> month >> year;
  while (n || day || month || year) {
    cout << day << " " << month << " " << year << endl;
    cin >> n >> day >> month >> year;
  }
  return 0;
}
