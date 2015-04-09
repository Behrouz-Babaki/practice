#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <utility>

using std::cin;
using std::ws;
using std::cout;
using std::endl;
using std::string;
using std::getline;
using std::vector;
using std::set;
using std::pair;
using std::make_pair;

int size;
vector<vector<char> > table;
struct comp{
  bool operator() (const string& lhs, const string& rhs) const {
    if (lhs.length() != rhs.length())
      return lhs.length() < rhs.length();
    return lhs < rhs;
  }
};
set<string,comp> results;
void search(int row, int col, set<pair<int, int> > s, string word);

int main(void) {
  int num_cases;
  cin >> num_cases;
  while (num_cases--) {
    size;
    cin >> size >> ws;
    table.clear();
    table.resize(size, vector<char>(size));
    for (int i=0; i<size; i++) {
      string line;
      getline(cin, line);
      int j = 0;
      for (auto ch : line)
	table[i][j++] = ch;
    }
    results.clear();
    for (int row=0; row<size; row++)
      for (int col=0; col<size; col++)
	{
	  set<pair<int,int> > s;
	  string str;
	  search(row, col, s, str);
	}
    for (auto word:results)
      cout << word << endl;
    if (num_cases > 0)
      cout << endl;
  }
  return 0;
}

void search(int row, int col, set<pair<int, int> > s, string word) {
  word.push_back(table[row][col]);
  if (word.length() >= 3)
    results.insert(word);
  s.insert(make_pair(row,col));
  int inc[3] = {-1, 0, 1};
  for (int i=0; i<3; i++)
    for (int j=0; j<3; j++)
      if (i!=1 || j!=1) {
	int r = row+inc[i];
	int c = col+inc[j];
	if (r >= 0 && r < size && 
	    c >= 0 && c < size) 
	  if (table[row][col] < table[r][c] && 
	      s.find(make_pair(r,c))==s.end()) 
	    search(r,c,s, word);
      }
}
