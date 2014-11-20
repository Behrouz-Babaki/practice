#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

using std::cin;
using std::ws;
using std::endl;
using std::cout;
using std::vector;
using std::getline;
using std::string;
using std::pair;
using std::make_pair;
using std::sort;

typedef pair<size_t, size_t> ss;
typedef vector<ss> vss;
typedef vector<size_t> vs;
typedef vector<vs> vvs;

#define TRvvs(c, it) \
  for (vvs::iterator it = (c).begin(), end = (c).end(); it != end; it++)

#define TRvss(c, it) \
  for (vss::iterator it = (c).begin(), end = (c).end(); it != end; it++)

size_t dfs_dice(vvs& types, vvs& visited, size_t row, size_t col);
void dfs_dots(vvs& types, vvs& visited, size_t row, size_t col);
vss neighbours (size_t row, size_t col, size_t w, size_t h);
void dfs_background(vvs& types, vvs& visited, size_t row, size_t col);

int main(void) {
  size_t w, h;
  string line;
  size_t case_counter = 1;
  cin >> w >> h >> ws;
  while (w > 0 && h > 0) {
    vvs types (h, vs(w, 0));
    vvs visited(h, vs(w, 0));
    for (size_t row_counter = 0; row_counter < h; row_counter++) {
      getline(cin, line);
      for (size_t col_counter = 0; col_counter < w; col_counter++) 
	switch(line.at(col_counter)) {
	case '.':
	  types[row_counter][col_counter] = 1;
	  break;
	case '*':
	  types[row_counter][col_counter] = 2;
	  break;
	case 'X':
	  types[row_counter][col_counter] = 3;
	  break;
	}
    }
    
    vs num_dots;
    for (size_t row_counter = 0; row_counter < h; row_counter++) 
      for (size_t col_counter = 0; col_counter < w; col_counter++) 
	if (!visited[row_counter][col_counter]){ 
	  if(types[row_counter][col_counter] == 2){
	    //cout << "\nnext@" << row_counter << ":" << col_counter << endl;
	    num_dots.push_back(dfs_dice(types, visited, row_counter, col_counter));
	  }
	  else
	    dfs_background(types, visited, row_counter, col_counter);
	}
	  
    sort(num_dots.begin(), num_dots.end());
    cout << "Throw " << case_counter++ << endl;
    for (size_t dot_cnt = 0, size = num_dots.size(); dot_cnt < size-1; dot_cnt++)
      cout << num_dots[dot_cnt] << " ";
    cout << num_dots[num_dots.size()-1] << endl;
    cout << endl;
    cin >> w >> h >> ws;
  }
  return 0;
}

size_t dfs_dice(vvs& types, vvs& visited, size_t row, size_t col) {
  //cout << "D" << row << ":" << col << "\t";
  size_t dots = 0;
  vss n = neighbours(row, col, types[0].size(), types.size());
  TRvss (n, it) 
    if (!visited[it->first][it->second]) {
      visited[it->first][it->second] = 1;
      if (types[it->first][it->second] == 2)
	dots += dfs_dice(types, visited, it->first, it->second);
      else if (types[it->first][it->second] == 3){
	dots++;
	dfs_dots(types, visited, it->first, it->second);
      }
  }
  return dots;
}

void dfs_dots(vvs& types, vvs& visited, size_t row, size_t col) {
  //cout << "T" << row << ":" << col << "\t";
  vss n = neighbours(row, col, types[0].size(), types.size());
  TRvss (n, it) 
    if (!visited[it->first][it->second] && types[it->first][it->second] == 3) {
      visited[it->first][it->second] = 1;
      dfs_dots(types, visited, it->first, it->second);
    }
}

void dfs_background(vvs& types, vvs& visited, size_t row, size_t col) {
  //cout << "B" << row << ":" << col << "\t";
  vss n = neighbours(row, col, types[0].size(), types.size());
  TRvss (n, it) 
    if (!visited[it->first][it->second] && types[it->first][it->second] == 1) {
      visited[it->first][it->second] = 1;
      dfs_background(types, visited, it->first, it->second);
    }
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
