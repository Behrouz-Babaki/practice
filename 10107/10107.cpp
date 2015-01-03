#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>

using std::endl;
using std::cout;
using std::cin;
using std::priority_queue;
using std::less;
using std::greater;
using std::vector;
using std::min;
using std::max;

int main(void) {
  int val;
  bool even = false;
  int median;
  priority_queue <int, vector<int> , less<int> > left;
  priority_queue <int, vector<int> , greater<int> > right;
  priority_queue <int, vector<int> , less<int> > left_temp;
  priority_queue <int, vector<int> , greater<int> > right_temp;

  cin >>  val;
  median = val;
  cout << median << endl;

  while (cin >> val) {
    if (!even) {
      even = true;
      int lower = min(median, val);
      int upper = max(median, val);
      left.push (lower);
      right.push(upper);
      median = (left.top() + right.top()) /2;
    }
    else {
      even = false;
      if (val < median) {
	left.push(val);
	median = left.top();
	left.pop();
      }
      else {
	right.push(val);
	median = right.top();
	right.pop();
      }
    }
    cout << median << endl;
  }
  return 0;
}

