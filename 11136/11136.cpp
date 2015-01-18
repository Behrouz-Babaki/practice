#include <iostream>
#include <set>

using std::cin;
using std::cout;
using std::endl;
using std::multiset;

int main(void) {
  size_t num_days;
  cin >> num_days;
  while (num_days) {
    multiset<size_t> bills;
    size_t cost = 0;
    for (size_t day_cnt = 0; day_cnt < num_days; day_cnt++) {
      size_t num_bills;
      cin >> num_bills;
      for(size_t bill_cnt = 0; bill_cnt < num_bills; bill_cnt++){
	size_t current_bill;
	cin >> current_bill;
	bills.insert(current_bill);
      }
      cost += (*(bills.rbegin()) - *(bills.begin()));
      auto last = bills.end();
      bills.erase(--last);
      bills.erase(bills.begin());
    }
    cout << cost << endl;
    cin >> num_days;
  }
  return 0;
}
