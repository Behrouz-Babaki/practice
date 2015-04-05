#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main(void) {
  int num_cases;
  cin >> num_cases;
  while (num_cases--) {
    int n;
    cin >> n;
    vector<int> sales(n);
    for (int counter = 0; counter < n; counter++)
      cin >> sales[counter];
    long sum = 0;
    for (int outer = 1; outer < n; outer++)
      for (int inner = 0; inner < outer; inner++)
	if (sales[inner] <= sales[outer])
	  sum++;
    cout << sum << endl;
  }
  return 0;
}
