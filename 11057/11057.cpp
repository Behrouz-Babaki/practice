#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::sort;
using std::min;
using std::max;
using std::binary_search;

int main(void) {
  int n;
  while (cin >> n){
    vector<int> prices(n);
    for(int i=0; i<n; i++)
      cin >> prices[i];
    int money;
    cin >> money;
    sort(prices.begin(), prices.end());
    int val, diff;
    diff = money;
    for (int i=0; i<n; i++) 
      if (abs(2*prices[i]-money) < diff)
	if (binary_search(prices.begin(), prices.end(), money-prices[i])) {
	  val = prices[i];
	  diff = abs(money-2*prices[i]);
	}
    cout << "Peter should buy books whose prices are " << 
      min(val, money-val) << " and " <<
      max(val, money-val) << "." << endl;
    cout << endl;
  }
  return 0;
}
