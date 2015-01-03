#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <utility>

using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::getline;
using std::string;
using std::ws;
using std::istringstream;
using std::pair;
using std::make_pair;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<size_t> vs;
typedef vector<vs> vvs;
typedef pair<size_t, size_t> ss;
typedef vector<ss> vss;

#define TRvss(c, it) \
  for (vss::iterator it = (c).begin(), eit = (c).end(); it != eit; it++)

void dfs (vvs& land, vvi& dfs_num, size_t row, size_t col, size_t color);
vss neighbours (size_t row, size_t col, size_t w, size_t h);

vs areas;
size_t current_area;

int main(void) {
  size_t number_of_cases;
  cin >> number_of_cases >> ws; 
  string line;
  bool first = true;

  for (size_t case_cnt = 0; case_cnt < number_of_cases; case_cnt++) {
    if (first)
      first = false;
    else 
      cout << endl;

    vvs land;
    getline(cin, line);
    while (line.at(0) == 'L' || line.at(0) == 'W') {
      vs row_vec;
      for (string::iterator it = line.begin(); it != line.end(); it++)
	row_vec.push_back (*it == 'L');
      land.push_back(row_vec);
      getline(cin, line);
    }
    size_t w, h;
    h = land.size();
    w = land[0].size();
    areas.clear();
    vvi dfs_num (h, vi(w, -1));
    size_t color = 0;
    for (size_t row_cnt = 0; row_cnt < h; row_cnt++)
      for (size_t col_cnt = 0; col_cnt < w; col_cnt++)
	if (dfs_num[row_cnt][col_cnt] < 0) {
	  current_area = 0;
	  dfs(land, dfs_num, row_cnt, col_cnt, color++);
	  areas.push_back(current_area);
	}

    istringstream ss(line);
    size_t row, col;
    ss >> row >> col;
    while (!ss.fail()) {
      cout << areas[dfs_num[row-1][col-1]] << endl;
      getline(cin, line);
      ss.clear();
      ss.str(line);
      ss >> row >> col;
    }
  }

  return 0;
}

void dfs (vvs& land, vvi& dfs_num, size_t row, size_t col, size_t color) {
  dfs_num[row][col] = color;
  current_area++;
  vss n = neighbours(row, col, land[0].size(), land.size());
  TRvss (n, it) 
    if (dfs_num[it->first][it->second] < 0 && land[it->first][it->second] == land[row][col]) 
      dfs(land, dfs_num, it->first, it->second, color);
}

vss neighbours (size_t row, size_t col, size_t w, size_t h) {
  vss n;

  if (row > 0) {
    n.push_back(make_pair(row-1, col));
  if (col > 0)
    n.push_back(make_pair(row-1, col-1));
  if (col < w-1)
    n.push_back(make_pair(row-1, col+1));
  }

  if (row < h-1) {
    n.push_back(make_pair(row+1, col));
  if (col > 0)
    n.push_back(make_pair(row+1, col-1));
  if (col < w-1)
    n.push_back(make_pair(row+1, col+1));
  }

  if (col > 0)
    n.push_back(make_pair(row, col-1));
  if (col < w-1)
    n.push_back(make_pair(row, col+1));
  
  return n;
}
