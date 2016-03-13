#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::ws;
using std::string;
using std::stringstream;
using std::getline;
using std::vector;

class union_find{
public :
  union_find(int num_items) {
    parents.reserve(num_items);
    for (int i=0; i<num_items; i++)
      parents[i] = i;
  }

  int find_set(int id) {
    if (parents[id] != id) 
      parents[id] = find_set(parents[id]);
    return parents[id];
  }

  void union_set(int id1, int id2) {
    parents[find_set(id1)] = find_set(id2);
  }

  vector<int> parents;
};

int main(void) {
  int num_cases;
  cin >> num_cases >> ws;

  string line;

  while (num_cases--) {
    int num_computers;
    cin >> num_computers >> ws;
    union_find uf(num_computers);
    getline(cin, line);
    int good = 0, bad = 0;
    while (!line.empty()) {
      stringstream ss(line);
      char c;
      int first; 
      int second;
      ss >> c >> first >> second;
      if (c == 'c')
	uf.union_set(first-1, second-1);
      if (c == 'q')
	if (uf.find_set(first-1) == uf.find_set(second-1))
	  good ++;
	else
	  bad++;
      getline(cin, line);
    }
    cout << good << "," << bad << endl;
    if (num_cases)
      cout << endl;
  }
}
