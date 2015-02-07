#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main(void) {
  size_t num_cases;
  cin >> num_cases;
  for (int case_counter = 0; case_counter < num_cases; case_counter++) {
    size_t a, b;
    cin >> a >> b;
    if (!(a%2))
      a++;
    if (!(b%2))
      b--;
    size_t num_odds, sum_odds;
    num_odds = (b-a)/2 + 1;
    sum_odds = (a+b)*(num_odds)/2;
    cout << "Case " << case_counter + 1 << ": " << sum_odds << endl;
  }
  return 0;
}
