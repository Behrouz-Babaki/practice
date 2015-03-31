#include <iostream>
#include <string>
#include <queue>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::queue;

int main(void) {
  int cnt;
  cin >> cnt;
  while (cnt--) {
    int l, m;
    cin >> l >> m;
    queue<int> left, right;
    while (m--) {
      int length;
      string side;
      cin >> length >> side;
      if (!side.compare("left"))
	left.push(length);
      else
	right.push(length);
    }
    int side = 0;
    int times = 0;
    while (!left.empty() || !right.empty()) {
      int rem = l * 100;
      queue<int>& q = side ? right : left;
      queue<int>& other = side ? left : right;

      while (!q.empty() && rem > q.front()) {
	rem -= q.front();
	q.pop();
      }
      if (!other.empty()) {
	side = !side;
	times++;
      }
      else if (!q.empty()) 
	times += 2;
    }
    cout << times << endl;
  }
    return 0;
  }
