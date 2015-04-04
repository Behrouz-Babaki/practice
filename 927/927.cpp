#include <iostream>
#include <vector>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main(void) {
  int num_cases;
  cin >> num_cases;
  while (num_cases--) {
    int degree;
    cin >> degree;
    vector<int> coefs(degree+1);
    for (int counter = 0; counter <= degree; counter++)
      cin >> coefs[counter];
    int d, k;
    cin >> d >> k;
    int mid = sqrt(2*k/d);
    int high = mid + 1;
    int low = mid - 1;
    int n;
    if ((2*k >= mid * (mid+1) * d) &&
	(2*k < (mid+1)*(mid+2)*d))
      n = mid;
    else if ((2*k >= high * (high+1) * d) &&
	     (2*k < (high+1)*(high+2)*d))
      n = high;
    else if ((2*k >= low * (low+1) * d) &&
	     (2*k < (low+1)*(low+2)*d))
      n = low;
    //cout << n << endl;
    long result = 0;
    for (int counter = 0; counter <= degree; counter++)
      result += (coefs[counter] * pow(n, counter));
    cout << result << endl;
  }
  return 0;
}
