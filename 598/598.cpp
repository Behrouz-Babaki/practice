#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <set>
#include <vector>

using std::cin;
using std::ws;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::istringstream;
using std::set;
using std::vector;

void print_subsets(const vector<string>& names, int s_size);

int main(void) {
  int num_cases;
  cin >> num_cases >> ws;
  while (num_cases--) {
    string line;
    getline(cin, line);
    istringstream ss(line);
    int first, second;
    bool all = false, ub = false;
    if(line.front() == '*')
      all = true;
    else {
      ss >> first;
      if (ss >> second)
	ub = true;
      else
	second = first;
    }
    vector<string> names;
    getline(cin, line);
    while (line.length()) {
      names.push_back(line);
      getline(cin, line);
    }

    if (all){
      first = 1;
      second = names.size();
    }
    
    for (int i=first; i<=second; i++) {
      cout << "Size " << i << endl;
      print_subsets(names, i);
      cout << endl;
    }
    if (num_cases)
      cout << endl;
  }
  return 0;
}

void print_subsets(const vector<string>& names, int s_size) {
  int size = names.size();
  int i;
  i |= (1<<size);
  i--;
  while (i){
    int count = 0;
    vector<string> s;
    for (int j=0; count<=s_size && j < size; j++)
      if (i&(1<<j))
	count++;
    if (count == s_size) {
      for (int j=0; j<size; j++)
	if (i&(1<<(size-j-1)))
	  s.push_back(names[j]);
      for (int k=0; k<s.size(); k++){
	if (k)
	  cout << ", ";
	cout << s[k];
      }
      cout << endl;
    }
    i--;
  }
}
