#include <iostream>
#include <vector> 

using std::cin;
using std::endl;
using std::cout;
using std::vector;
using std::ws;

vector<vector<int> > grid;
vector<vector<int> > visited;

int N;
int num_ships;

void visit(int r, int c);
 
int main(void) {
  int T;
  cin >> T;
  for (int case_cnt = 1; case_cnt <= T; case_cnt++){

    cin >> N >> ws;
    num_ships = 0;

    grid.clear();
    visited.clear();
    
    grid.resize(N, vector<int>(N));
    visited.resize(N, vector<int>(N));

    char ch;
    for (int r=0; r<N; r++) {
      for(int c=0; c<N; c++) {
	cin >> ch;
	switch(ch) {
	case '.':
	  grid[r][c] = 0;
	  break;
	case 'x':
	  grid[r][c] = 1;
	  break;
	case '@':
	  grid[r][c] = 2;
	  break;
	}
      }
	cin >> ws;
    }
    
    for (int r=0; r<N; r++)
      for (int c=0; c<N; c++) 
	if (grid[r][c] == 1 && !visited[r][c]){
	  num_ships++;
	  visit(r,c);
      }
    cout << "Case " << case_cnt << ": " << num_ships << endl;
  }
  return 0;
}

void visit(int r, int c) {
  int h, v;
  h =  (((c-1) >= 0 && grid[r][c-1]) ||
	((c+1) < N && grid[r][c+1]));
  v = 1-h;

  int col = c, row = r;
  while (col >= 0 && row >= 0 && grid[row][col]) {
    visited[row][col] = 1;
    col -= h;
    row -= v;
  }
  col = c, row = r;
  while (col < N && row < N && grid[row][col]) {
    visited[row][col] = 1;
    col += h;
    row += v;
  }
}
