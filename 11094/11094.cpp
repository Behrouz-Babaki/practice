#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::ws;

vector<vector<int> > grid;
void print_vec(vector<vector<int> >& v);

int main(void){
  int M, N;
  while (cin  >> M >> N >> ws) {
    grid.clear();
    grid.resize(M, vector<int>(N));
    for (int r=0; r<M; r++) {
      for (int c=0; c<N; c++) {
	char ch;
	cin >> ch;
	grid[r][c] = (ch=='l');
      }
      cin >> ws;
    }

    int x, y;
    cin >> x >> y;
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
