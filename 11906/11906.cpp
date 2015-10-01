#include <iostream>
#include <vector>
#include <set>
#include <utility>

using std::endl;
using std::cin;
using std::cout;
using std::vector;
using std::set;
using std::pair;
using std::make_pair;

vector<vector<int> > visited;
vector<vector<int> > accessible;
int R, C, M, N;
int odds, evens;

void dfs(int row, int col);
void print_vec(vector<vector<int> >& v);

int main(void) {
  int T;
  cin >> T;
  int case_cnt = 1;
  while (case_cnt<=T) {

    cin >> R >> C >> M >> N;
    visited.clear();
    visited.resize(R, vector<int> (C));
    accessible.clear();
    accessible.resize(R, vector<int> (C, 1));

    int W; 
    cin >> W;
    for (int cnt=0; cnt<W; cnt++) {
      int wr, wc;
      cin >> wr >> wc;
      accessible[wr][wc] = 0;
    }
    odds = evens = 0;
    dfs(0,0);
    cout << "Case " << case_cnt << ": " << evens << " " << odds << endl;
    case_cnt++;
  }
  return 0;
}

void dfs(int r, int c) {
  visited[r][c] = 1;
  set<pair<int,int> > neighbours;
  for (int rr=-1; rr<=1; rr+=2)
    for(int cc=-1; cc<=1; cc+=2) {
      int row = r+rr*M;
      int col = c+cc*N;
      if (row >=0 && row < R &&
	  col >=0 && col < C && 
	  accessible[row][col]){
	neighbours.insert(make_pair(row, col));
	if(!visited[row][col]) 
	  dfs(row,col);
      }

      if (M!=N) {
	row = r+rr*N;
	col = c+cc*M;
	if (row >=0 && row < R &&
	    col >=0 && col < C && 
	    accessible[row][col]){
	  neighbours.insert(make_pair(row, col));
	  if(!visited[row][col])
	    dfs(row,col);
	}
      }
    }
  if (neighbours.size()%2)
    odds++;
  else
    evens++;
}

void print_vec(vector<vector<int> >& v){
  for (auto r : v){
    for (auto c : r)
      cout << c << "\t";
    cout << endl;
  }
}
  
