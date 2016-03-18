#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::pair;
using std::make_pair;
using std::sort;

int main(void) {
  int num_cases;
  cin >> num_cases;
  for (int case_cnt=0; case_cnt<num_cases; case_cnt++) {
    int n_cities, n_roads, a_cost;
    cin >> n_cities >> n_roads >> a_cost;
    vector<pair<int, pair<int, int> > > roads(n_roads);
    for (int i=0; i < n_roads; i++) {
      int first, second, cost;
      cin >> first >> second >> cost;
      roads[i] = make_pair(cost, make_pair(first-1, second-1));
    }
    sort(roads.begin(), roads.end());
  }
  return 0;
}

