#include <iostream>
#include <vector>

using std::endl;
using std::cin;
using std::cout;
using std::vector;

vector<vector<int> > visited;
vector<vector<int> > accessible;
int R, C, M, N;

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

    dfs(0,0);
    // print_vec(visited);
    int odds = 0, evens = 0;
    for (int r=0; r<R; r++)
      for (int c=0; c<C; c++) 
	if (visited[r][c]){
	int cnt = 0; 
	for (int rr=-1; rr<=1; rr+=2)
	  for(int cc=-1; cc<=1; cc+=2) {
	    int row = r+rr*N;
	    int col = c+cc*M;
	    if (row >=0 && row < R &&
		col >=0 && col < C && visited[row][col])
	      cnt++;
	  }
	if (cnt%2)
	  odds++;
	else
	  evens++;
      }
    cout << "Case " << case_cnt << ": " << evens << " " << odds << endl;
    case_cnt++;
  }
  return 0;
}

void dfs(int r, int c) {
  visited[r][c] = 1;
  for (int rr=-1; rr<=1; rr+=2)
    for(int cc=-1; cc<=1; cc+=2) {
      int row = r+rr*N;
      int col = c+cc*M;
      if (row >=0 && row < R &&
	  col >=0 && col < C && 
	  accessible[row][col] && !visited[row][col])
	dfs(row,col);
    }

}

void print_vec(vector<vector<int> >& v){
  for (auto r : v){
    for (auto c : r)
      cout << c << "\t";
    cout << endl;
  }
}
  
