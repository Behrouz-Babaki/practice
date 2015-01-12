#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <iomanip>

using std::cout;
using std::endl;
using std::cin;
using std::ws;
using std::string;
using std::map;
using std::getline;
using std::make_pair;
using std::setprecision;
using std::fixed;

int main(void) {
  size_t num_cases;
  cin >> num_cases >> ws;;
  string line;

  for (size_t case_counter = 0; case_counter < num_cases; case_counter++) {
    map<string, size_t> tree_map;
    double total = 0;
    getline(cin, line);
    while (line.size()){
      map<string, size_t>::iterator itr = tree_map.find(line);
      if (itr != tree_map.end())
	(itr->second)++;
      else
	tree_map.insert(make_pair(line, 1));
      total++;
      getline(cin, line);
    }
    for (auto itr = tree_map.begin(), end = tree_map.end();
	 itr != end; itr++)
      cout << itr->first << " " << fixed << setprecision(4) << (itr->second)*100/total << endl;

    if (case_counter < num_cases-1)
      cout << endl;
  }
  return 0;
}
