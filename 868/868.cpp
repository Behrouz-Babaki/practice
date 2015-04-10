#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::set;
using std::pair;
using std::make_pair;

set<pair<int,int> > ends;
vector<vector<int> > maze;

void search(int row, int col, int finish);

int main(void) {
  int num_cases;
  cin >> num_cases;
  while (num_cases--) {
    int rows, cols;
    cin >> rows >> cols;
    maze.clear();
    maze.resize(rows, vector<int>(cols));
    for (int i=0; i<rows; i++)
      for (int j=0; j<cols;j++)
	cin >> maze[i][j];
    bool found=false;
    for (int i=0; !found && i<cols; i++)
      if (maze[0][i] == 1) {
	ends.clear();
	search(0, i, 1);
	if (!ends.empty()) {
	  cout << 1 << " " << i+1 << endl;
	  cout << (ends.begin()->first)+1 << " " <<
	    (ends.begin()->second)+1 << endl;
	  found=true;
	}
      }
    if (num_cases)
      cout << endl;
  }
  return 0;
}

void search(int row, int col, int finish){
  int val = maze[row][col];
  if (row == maze.size()-1 
      && val == finish) {
    ends.insert(make_pair(row, col));
    return;
  }
  int next = val+1;
  if(val == finish) { 
    next = 1;
    finish++;
  }
  int inc[4][2] = {
    {-1,0},
    {1,0},
    {0,-1},
    {0,1}
  };
  for(int i=0; i<4; i++) {
    int next_row = row+inc[i][0];
    int next_col = col+inc[i][1];
    if (next_row>=0 && next_row<maze.size() &&
	next_col>=0 && next_col<maze.front().size() &&
	maze[next_row][next_col]==next)
      search(next_row, next_col, finish);
  }
  return;
}
