#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <string>
#include <algorithm>

using std::cout;
using std::endl;
using std::cin;
using std::queue;
using std::pair;
using std::make_pair;
using std::string;
using std::vector;
using std::min;
using std::max;

int main(void) {
  int c;
  cin >> c;
  while (c--) {
    int n, t, m;
    cin >> n >> t >> m;
    queue <pair<int, int> > left, right;
    for (int num = 0; num < m; num++) {
      int time;
      string side_str;
      cin >> time >> side_str;
      pair<int, int> current = make_pair(num, time);
      if(side_str.compare("left"))
	right.push(current);
      else
	left.push(current);
    }
    bool side = 0;
    int time = 0;
    queue<int> load;
    vector<int> unloads(right.size() + left.size());
    while (!right.empty() || !left.empty()) {
      queue<pair<int,int> >& current = side ? right : left;
      queue<pair<int,int> >& other = side ? left : right;
      int loaded = 0;
      /// improve the logic here
      if (!current.empty() && current.front().second > time) {
	if (!other.empty() && other.front().second < current.front().second)
	  time = max(time, other.front().second);
	else
	  time = current.front().second;
      }
      if (current.empty() && time < other.front().second)
	time = other.front().second;
      ///
      while (!current.empty() && current.front().second <= time && loaded++ < n) {
	load.push(current.front().first);
	current.pop();
      }
      time += t;
      while (!load.empty()) {
	unloads[load.front()] =  time;
	load.pop();
      }
      side = !side;
    }
    for (auto u : unloads)
      cout << u << endl;
    if (c)
      cout << endl;
  }
  return 0;
}
