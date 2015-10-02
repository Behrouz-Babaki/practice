#include <iostream>
#include <vector>
#include <utility>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::ws;
using std::pair;
using std::make_pair;

vector<vector<int> > grid;
vector<vector<int> > visited;
int count;
int M, N;
void print_vec(vector<vector<int> >& v);
vector<pair<int, int> > get_adjacent(int x, int y);
void dfs(int, int);

int main(void){

  while (cin  >> M >> N >> ws) {
    grid.clear();
    visited.clear();
    
    grid.resize(M, vector<int>(N));
    visited.resize(M, vector<int>(N));
    
    bool first = true;
    char ref;
    for (int r=0; r<M; r++) {
      for (int c=0; c<N; c++) {
	if (first) {
	  grid[r][c] = 1;
	  cin >> ref;
	  first = false;
	}
	else {
	  char ch;
	  cin >> ch;
	  grid[r][c] = (ch==ref);
	}
      }
      cin >> ws;
    }
    
    int x, y;
    cin >> x >> y;
    if (!grid[x][y]) {
      for (int r=0; r<M; r++)
	for (int c=0; c<N; c++)
	  grid[r][c] = (1-grid[r][c]);
    }

    dfs(x, y);

    int max_count = 0;
    for (int r=0; r<M; r++)
      for (int c=0; c<N; c++){
      count = 0;
      if (grid[r][c] && !visited[r][c])
	dfs(r, c);
      if (count > max_count)
	max_count = count;
    }
    cout << max_count << endl;
  }
  return 0;
}

void print_vec(vector<vector<int> >& v) {
  for (auto r : v) {
    for (auto c : r)
      cout << c << " ";
    cout << endl;
  }
}

vector<pair<int, int> > get_adjacent(int x, int y) {
  vector<pair<int, int> > result;
  int row , col;

  row = x;
  col = (y-1);
  if (col < 0)
    col = N-1;
  if (grid[row][col]) 
    result.push_back(make_pair(row, col));
  
  col = (y+1)%N;
  if (grid[row][col]) 
    result.push_back(make_pair(row, col));

  col = y;
  row = x-1;
  if (row >= 0 && grid[row][y])
    result.push_back(make_pair(row, col));

  row = x+1;
  if (row < M && grid[row][y])
    result.push_back(make_pair(row, col));

  return result;
}

void dfs(int x, int y){
  visited[x][y] = 1;
  count++;
  vector<pair<int, int> > adj = 
    get_adjacent(x, y);
  for (auto p : adj)
    if (!visited[p.first][p.second])
      dfs(p.first, p.second);
}
