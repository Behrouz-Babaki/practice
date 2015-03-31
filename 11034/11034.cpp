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

  }
  return 0;
}
