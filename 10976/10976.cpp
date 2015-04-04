#include <iostream>
#include <vector>
#include <utility>

using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::pair;
using std::make_pair;

int main(void) {
  int k;
  while (cin >> k) {
    vector<pair<int, int> > sols;
    int first, second;
    second = k + 1;
    bool done = false;
    while (!done) {
      int val = (k*second) / (second-k);
      if (val < k+1)
	done = true;
      if (!done && (k*second)%(second-k)==0) {
	first = val;
	if (first >= second)
	  sols.push_back(make_pair(first, second));
	else
	  done = true;
      }
      second++;
    }
    cout << sols.size() << endl;
    for (auto sol:sols) {
      cout << "1/" << k << " = 1/" << sol.first << " + 1/" << sol.second << endl;
    }
  }
  return 0;
}
