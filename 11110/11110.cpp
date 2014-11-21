#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::pair;
using std::make_pair;
using std::ws;
using std::istringstream;

typedef pair<size_t, size_t> ss;
typedef vector<ss> vss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<size_t> vs;
typedef vector<vs> vvs;
typedef vector<bool> vb;

vvs colors;
vvs visited;
vb used_colors;
size_t n;

#define TRvvs(c, it) \
  for (vvs::iterator it = (c).begin(), end = (c).end(); it != end; it++)

#define TRvss(c, it) \
  for (vss::iterator it = (c).begin(), end = (c).end(); it != end; it++)

void flood_fill(size_t row, size_t col, size_t current_color);
vss neighbours (size_t row, size_t col, size_t w, size_t h);

int main (void) {

  cin >> n >> ws;
  while (n > 0) {

    colors.clear();
    colors.resize(n, vs(n, n-1));
    visited.clear();
    visited.resize(n, vs(n, 0));
    used_colors.clear();
    used_colors.resize(n, false);

    string line;
    for (size_t line_cnt = 0; line_cnt < n-1; line_cnt++) {
      getline(cin, line);
      istringstream ss(line);
      while (!ss.fail()) {
	size_t row, col;
	ss >> row >> col;
	colors[row-1][col-1] = line_cnt;
      }
    }

    bool wrong = false;
    for (size_t row_cnt = 0; !wrong && row_cnt < n; row_cnt++)
      for (size_t col_cnt = 0; !wrong && col_cnt < n; col_cnt++)
	if (!visited[row_cnt][col_cnt]) {
	  size_t current_color = colors[row_cnt][col_cnt];
	  if (used_colors[current_color])
	    wrong = true;
	  else {
	    used_colors[current_color] = true;
	    flood_fill (row_cnt, col_cnt, current_color);
	  }
	}
      
    if (wrong)
      cout << "wrong" << endl;
    else
      cout << "good" << endl;
    cin >> n >> ws;
  }
  return 0;
}

void flood_fill(size_t row, size_t col, size_t current_color) {
  visited[row][col] = 1;
  vss ns = neighbours(row, col, n, n);
  TRvss (ns, it) 
    if (!visited[it->first][it->second] && colors[it->first][it->second] == current_color) 
      flood_fill(it->first, it->second, current_color);
}

vss neighbours (size_t row, size_t col, size_t w, size_t h) {
  vss n;
  if (row > 0)
    n.push_back(make_pair(row-1, col));
  if (row < h-1)
    n.push_back(make_pair(row+1, col));
  if (col > 0)
    n.push_back(make_pair(row, col-1));
  if (col < w-1)
    n.push_back(make_pair(row, col+1));
  
  return n;
}
