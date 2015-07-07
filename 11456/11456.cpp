#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::max_element;
using std::max;

int main(void) {
  int num_cases;
  cin >> num_cases;
  for (int case_cnt = 0; case_cnt < num_cases; case_cnt++) {
    int num_cars;
    cin >> num_cars;
    if (!num_cars){
      cout << 0 << endl;
      continue;
    }
    vector<int> cars(num_cars);
    for (int i=0; i<num_cars; i++)
      cin >> cars[i];

    vector<int> lds(num_cars, 0);
    vector<int> lis(num_cars, 0);
    
    for (int i=num_cars-1; i>=0; i--) {
      int best_head = 0;
      int best_tail = 0;
      for (int j=num_cars-1; j>i; j--) {
	if (cars[j] < cars[i] && lds[j] > best_head)
	  best_head = lds[j];
	if (cars[j] > cars[i] && lis[j] > best_tail)
	  best_tail = lis[j];
      }
      lis[i] = best_tail + 1;
      lds[i] = best_head + 1;
    }

    int l=1;
    for (int i=0; i<num_cars; i++)
      if (lds[i]+lis[i] > l)
	l = lds[i] + lis[i];
    cout << l-1 << endl;
  }
  return 0;
}
