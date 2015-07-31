#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::pair;
using std::make_pair;
using std::sqrt;
using std::pow;

int main(void) {
  int num_cases;
  cin >> num_cases;
  for (int case_cnt = 0; case_cnt <num_cases; case_cnt++) {
    int n_types, sum;
    cin >> n_types >> sum;

    vector<pair<int, int> > components;
    for (int cnt = 0; cnt <=sum; cnt++) {
      int res2 = pow(sum, 2) - pow(cnt, 2);
      int sq = sqrt(res2);
      if (sq*sq == res2)
	components.push_back(make_pair(cnt, sq));
    }

    vector<pair<int, int> > type_info(n_types);
    for (int type_cnt =0; type_cnt < n_types; type_cnt++) {
      int conv, it;
      cin >> conv >> it;
      type_info[type_cnt] = make_pair(conv, it);
    }

    int min_count; 
    bool first = true;
    for (auto component : components) {
      int conv = component.first;
      int it = component.second;
      vector<vector<int> > coins(n_types, vector<int> (max(conv, it)));
      // the rest
    }
    
    cout << "not possible" << endl;
  }
  return 0;
}
