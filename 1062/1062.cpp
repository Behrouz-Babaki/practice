#include <iostream>
#include <string>
#include <map>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::map;
using std::vector;

int main(void) {
  string line;
  cin >> line;
  int case_num = 1;
  while (line != "end") {
    map<char, vector<int> > containers;
    for (int cnt = 0, size = line.size(); cnt < size; cnt++) {
      char ship = line[cnt];
      if (containers.find(ship) == containers.end()) 
	containers[ship] = vector<int> ();
      containers[ship].push_back(cnt);
    }
    int min_stack = line.length();
    //perform the search here!
    cout << "Case " << case_num++ << ": " << min_stack << endl;
    // for (auto c : containers) {
    //   cout << c.first << " : ";
    //   for (auto n : c.second)
    // 	cout << n << " ";
    //   cout << endl;
    // }
    // cout << endl;
    cin >> line;
  }
  return 0;
}
