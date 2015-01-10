#include <iostream>
#include <string>
#include <map>

using std::cin;
using std::ws;
using std::cout;
using std::endl;
using std::string;
using std::map;

int main(void) {
  int num_cases;
  cin >> num_cases >> ws;
  map<string, size_t> conquests;
  string line;
  for (size_t counter = 0; counter < num_cases; counter++) {
    getline(cin, line);
    size_t i = 0;
    while (line.at(i) != ' ') i++;
    string country = line.substr(0,i);
    if (conquests.find(country) == conquests.end())
      conquests[country] = 1;
    else
      conquests[country]++;
  }
  for (auto itr = conquests.begin(), end = conquests.end();
       itr != end; itr++)
    cout << itr->first << " " << itr->second << endl;
  return 0;
}
