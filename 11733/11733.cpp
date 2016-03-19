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

vector<int> parents;
vector<int> ranks;

void union_set(int, int);
int find_set(int);

int main(void) {
  int num_cases;
  cin >> num_cases;
  for (int case_cnt=1; case_cnt<=num_cases; case_cnt++) {
    int n_cities, n_roads, a_cost;
    cin >> n_cities >> n_roads >> a_cost;
    vector<pair<int, pair<int, int> > > roads(n_roads);
    for (int i=0; i < n_roads; i++) {
      int first, second, cost;
      cin >> first >> second >> cost;
      if (cost < a_cost)
	roads[i] = make_pair(cost, make_pair(first-1, second-1));
    }
    sort(roads.begin(), roads.end());
    parents.resize(n_cities);
    for (int i=0; i<n_cities; i++)
      parents[i] = i;
    ranks.assign(n_cities, 0);

    int k = 0, total_cost = 0;
    for (int i=0, s=roads.size(); k<n_cities && i<s; i++){
      int first, second, cost;
      cost = roads[i].first;
      first = roads[i].second.first;
      second = roads[i].second.second;
      if (find_set(first)!=find_set(second)){
	k++;
	union_set(first, second);
	total_cost += cost;
      }
    }
    
    int num_airports = (n_cities - k);
    cout << "Case #" << case_cnt << ": " 
	 << (total_cost + num_airports * a_cost) 
	 << " " << num_airports << endl;
  }
  return 0;
}

int find_set(int id){
  if (parents[id] != id)
    parents[id] = find_set(parents[id]);
  return parents[id];
}

void union_set(int first, int second) {
  first = find_set(first);
  second = find_set(second);
  if (ranks[first] < ranks[second])
    parents[first] = second;
  else if (ranks[second] < ranks[first])
    parents[second] = first;
  else {
    ranks[first]++;
    parents[second] = first;
  }
}
