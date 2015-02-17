#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <cctype>

using std::cout;
using std::cin;
using std::endl;
using std::ws;
using std::make_pair;
using std::vector;
using std::map;
using std::multiset;
using std::multimap;
using std::string;
using std::sort;
using std::isspace;

void remove_blanks(string&);

int main(void) {
  size_t num_cases;
  cin >> num_cases >> ws;
  for (size_t case_counter = 0; case_counter < num_cases; case_counter++) {
    string line;
    map<string, size_t> key_map;
    vector<multiset<string> > multiset_vec;
    multimap <string, string> pairs;
    getline(cin, line);
    string line_copy(line);
    remove_blanks(line_copy);
    while (!line_copy.empty()) {
      sort(line_copy.begin(), line_copy.end());
      map<string, size_t>::iterator itr = key_map.find(line_copy);
      if (itr == key_map.end()) {
	multiset<string> new_multiset;
	new_multiset.insert(line);
	key_map.insert(make_pair(line_copy, multiset_vec.size()));
	multiset_vec.push_back(new_multiset);
      }
      else {
	size_t multiset_id = itr->second;
	multiset_vec[multiset_id].insert(line);
      }
      getline(cin, line);
      line_copy = line;
      remove_blanks(line_copy);
    }
    

    for (map<string, size_t>::iterator itr = key_map.begin(); itr != key_map.end(); itr++) {
      size_t index = itr->second;
      multiset<string>& current_multiset = multiset_vec[index];
      for (multiset<string>::iterator itr2 = current_multiset.begin(); itr2 != current_multiset.end(); itr2++) {
	multiset<string>::iterator itr3 = itr2;
	itr3++;
	for (; itr3 != current_multiset.end(); itr3++)
	  pairs.insert(make_pair(*itr2, *itr3));
      }
    } 
    for (auto pair: pairs)
      cout << pair.first << " = " << pair.second << endl;
    if (case_counter < num_cases - 1)
      cout << endl;
  }
  return 0;
}

void remove_blanks(string& str) {
  string copy(str);
  str.clear();
  for (auto ch:copy)
    if (!isspace(ch))
      str.push_back(ch);
}
