#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::queue;
using std::pair;
using std::make_pair;

typedef pair<int, int> loc;
void printNRegs(vector<vector<bool> >&);
void giveNeighbours(int, int, loc, vector<loc>&);

int main(void){
  int m,n;
  cin >> m >> n;
  while (m > 0){
    char ch;
    vector<vector<bool> > region(m, vector<bool>(n));
    for (int rowCtr = 0; rowCtr < m; rowCtr++)
      for (int colCtr = 0; colCtr < n; colCtr++){
	cin >> ch;
	region[rowCtr][colCtr] = (ch == '@');
      }

    printNRegs(region);
    cin >> m >> n;
  }
  return 0;
}

void printNRegs(vector<vector<bool> >& region){
  int m = region.size();
  int n = region.front().size();
  int regs = 0;
  for (int rowCtr = 0; rowCtr < m; rowCtr++)
    for (int colCtr = 0; colCtr < n; colCtr++)
      if (region[rowCtr][colCtr]) 
	{
	  regs++;
	  queue<loc> plots;
	  vector<loc> neighbours;

	  giveNeighbours(m,n,make_pair(rowCtr, colCtr), neighbours);
	  region[rowCtr][colCtr] = false;

	  for (auto neighbour:neighbours)
	    if (region[neighbour.first][neighbour.second]){
	      plots.push(neighbour);
	      region[neighbour.first][neighbour.second] = false;
	    }

	  while (!plots.empty()){
	    loc current = plots.front();
	    plots.pop();

	    giveNeighbours(m,n,current, neighbours);
	    for (auto neighbour:neighbours)
	      if (region[neighbour.first][neighbour.second]){
		plots.push(neighbour);
		region[neighbour.first][neighbour.second] = false;
	      }
	  }
	}
  cout << regs << endl;
}

void giveNeighbours(int m, int n, loc cell, vector<loc>& neighbours){
  int r = cell.first;
  int c = cell.second;
  neighbours.clear();

  for (int row = r-1; row <= r+1 ; row++)
    if (row >=0 && row < m)
      for (int col = c-1; col <= c+1; col++)
	     if (col >=0 && col < n)
	       neighbours.push_back(make_pair(row,col));
}
