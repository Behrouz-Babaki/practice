#include <iostream>
#include <list>
#include <utility>

using std::cin;
using std::cout;
using std::endl;
using std::list;
using std::pair;
using std::make_pair;

typedef list<int>::iterator lit;

int main(void) {
  int n, d, r;
  cin >> n >> d >> r;
  while (n || d || r) {
    list<int> morning, evening;
    int val;
    for (int i = 0; i < n; i++) {
      cin >> val;
      morning.push_back(val);
    }
    for (int i = 0; i < n; i++) {
      cin >> val;
      evening.push_back(val);
    }
    int penalty = 0;
    while (!morning.empty()) {
      pair<lit,lit> best_pair = make_pair(morning.begin(), evening.begin());
      int best_val = abs(*morning.begin() + *evening.begin() - d);
      for (lit itr1 = morning.begin(), end1 = morning.end(); itr1!=end1; itr1++) 
	for(lit itr2 = evening.begin(), end2 = evening.end(); itr2!=end2; itr2++)
	  if (abs(*itr1 + *itr2 - d) < best_val) {
	    best_val = abs(*itr1+*itr2-d);
	    best_pair = make_pair(itr1,itr2);
	  }
      if (*(best_pair.first) + *(best_pair.second) > d)
	penalty += r * (*(best_pair.first) + *(best_pair.second) - d);
      morning.erase(best_pair.first);
      evening.erase(best_pair.second);
    }
    cout << penalty << endl;
    cin >> n >> d >> r;
  }

  return 0;
}
