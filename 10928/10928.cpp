#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <utility>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::ws;
using std::istringstream;
using std::stable_sort;
using std::string;
using std::pair;
using std::make_pair;

int main(void) {
  size_t num_cases;
  cin >> num_cases;
  bool first = true;
  string line;
  for (size_t case_cnt = 0; case_cnt < num_cases; case_cnt++) {
    if (first)
      first = false;
    else 
      getline(cin, line);
    size_t num_places;
    cin >> num_places >> ws;
    vector<pair<int, int> >neighbours;
    for (size_t place_cnt = 0; place_cnt < num_places; place_cnt++) {
      getline(cin, line);
      istringstream ss(line);
      int neighbour;
      size_t neighbour_count = 0;
      while (ss >> neighbour)
	neighbour_count++;
      neighbours.push_back(make_pair(place_cnt, neighbour_count));
    }
    stable_sort(neighbours.begin(), neighbours.end(), 
		[] (const pair<int, int>& left, const pair<int,int>& right) {
		  return (left.second < right.second);
		});
    cout << neighbours[0].first + 1;
    size_t counter = 1;
    while (counter < neighbours.size() && 
	   neighbours[counter].second == neighbours[0].second) {
      cout << " ";
      cout << neighbours[counter].first + 1;
      counter++;
    }
    cout << endl;
  }
  return 0;
}
