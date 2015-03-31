#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using std::cout;
using std::cin;
using std::endl;
using std::queue;
using std::vector;
using std::stack;

int main(void) {
  int set;
  cin >> set;
  while (set--) {
    int n, s, q;
    cin >> n >> s >> q;
    vector<queue<int> >  bs(n);
    for (int cnt = 0; cnt < n; cnt++) {
      int num;
      cin >> num;
      while (num--) {
	int dest;
	cin >> dest;
	bs[cnt].push(dest-1);
      }
    }
    
    stack<int> carrier;
    int station = 0, time = 0;
    bool done = false;
    while (!done) {

      while (!carrier.empty() && (bs[station].size() < q || carrier.top()==station)) {
	while (!carrier.empty() && carrier.top() == station) {
	  carrier.pop();
	  time++;
	}
	while (!carrier.empty() && carrier.top() != station && bs[station].size() < q) {
	  bs[station].push(carrier.top());
	  carrier.pop();
	  time++;
	}
      }
      
      while (carrier.size() < s && !bs[station].empty()) {
	carrier.push(bs[station].front());
	bs[station].pop();
	time++;
      }
      
      done = true;
      if (!carrier.empty())
	done = false;
      for (auto itr = bs.begin(), end = bs.end();
	   done && itr!=end; itr++)
	if (!(*itr).empty())
	  done = false;

      if (!done) {
	time += 2;
	station = (station+1) % n;
      }
    }
    cout << time << endl;
  }
  return 0;
}
