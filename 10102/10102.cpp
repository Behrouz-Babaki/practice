#include <iostream>
#include <utility>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::ws;
using std::vector;
using std::pair;
using std::make_pair;
using std::string;

int diff(const pair<int,int>&, 
	 const pair<int,int>&);

int main(void) {
  int m;
  while (cin >> m) {
    cin >> ws;
    vector<pair<int, int> > ones, threes;
    ones.reserve(m*m);
    threes.reserve(m*m);
    for (int row = 1; row <= m; row++) {
      string line;
      getline(cin, line);
      for (int col = 1; col <= m; col++) {
	int val = line[col-1] - 48;
	if (val == 1)
	  ones.push_back(make_pair(row,col));
	else if (val == 3)
	  threes.push_back(make_pair(row,col));
      }
    }
    int mindiff, maxdiff;
    maxdiff = -1;
    for (auto one : ones) {
      mindiff = -1;
      for (auto three : threes) {
	int d = diff(one,three);
	if (mindiff < 0 || d < mindiff)
	  mindiff = d;
      }
      if (maxdiff < 0 || mindiff > maxdiff)
	maxdiff = mindiff;
    }
    cout << maxdiff << endl;
  }
    return 0;
}

int diff(const pair<int,int>& left, 
	 const pair<int,int>& right) {
  int d1 = left.first - right.first;
  if (d1 < 0)
    d1 = -d1;
  int d2 = left.second - right.second;
  if (d2 < 0)
    d2 = -d2;
  return d1 + d2;
}
