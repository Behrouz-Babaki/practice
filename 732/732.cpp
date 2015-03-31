#include <iostream>
#include <string>
#include <stack>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::stack;
using std::vector;

string first, second;

void dfs (stack<char>&, vector<char>&, int, int);
int main(void) {
  while (cin >> first) {
    cin >> second;
    cout << "[" << endl;
    stack<char> s;
    vector<char> q;
    dfs(s, q, 0, 0);
    cout << "]" << endl;
  }
  return 0;
}

void dfs(stack<char>& s, vector<char>& q, int pos1, int pos2) {
  if (pos2 == second.size()) {
    for (int i = 0, size = q.size();
	 i < size; i++) {
      cout << q[i];
      if (i < size-1)
	cout << " ";
    }
    cout << endl;
    return;
  }

  // option push
  if (pos1 < first.size()){
  q.push_back('i');
  s.push(first[pos1]);
  dfs(s, q, pos1+1, pos2);
  s.pop();
  q.pop_back();
  }
  // option pop
  if (!s.empty() && (s.top() == second[pos2])){
    q.push_back('o');
    s.pop();
    dfs(s, q, pos1, pos2+1);
    s.push(second[pos2]);
    q.pop_back();
  }
}
