#include <iostream>
#include <algorithm>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::sort;

int main(void) {
  int n;
  cin >> n;
  int case_counter = 1;
  while (n) {
    vector<int> numbers(n);
    for (int counter = 0; counter < n; counter++)
      cin >> numbers[counter];
    sort(numbers.begin(), numbers.end());
    cout << "Case " << case_counter << ":" << endl;
    int m;
    cin >> m;
    while (m--) {
      int query; 
      cin >> query;
      cout << "Closest sum to " << query << " is ";
      int distance = (query - numbers[0] - numbers[1]);
      if (distance < 0)
	distance = -distance;
      int closest = numbers[0] + numbers[1];
      bool equal = false;
      for (int cnt1 = 0, size = numbers.size(); !equal && cnt1 < size; cnt1++) {
	bool stop = false;
	for (int cnt2 = cnt1 + 1, size = numbers.size(); !stop && cnt2 < size; cnt2++){
	  int diff = (numbers[cnt1] + numbers[cnt2] - query);
	  if (diff < 0)
	    diff = -diff;
	  if (diff < distance) {
	    distance = diff;
	    closest = numbers[cnt1] + numbers[cnt2];
	    if (diff == 0) {
	      stop = true;
	      equal = true;
	    }
	  }
	  if (numbers[cnt1] + numbers[cnt2] > query)
	    stop = true;
	}
      }
      
      cout << closest << "." << endl;
    }

    cin >> n;
    case_counter++;
  }
  return 0;
}
