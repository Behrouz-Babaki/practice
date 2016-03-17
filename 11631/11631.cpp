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
int find_set(int);
void union_set(int, int);

int main(void) {
  int m, n;
  cin >> m >> n;
  int32_t total;
  while (m && n){
    vector<pair<int, pair<int, int> > >streets(n);
    total = 0;
    for (int i=0; i<n; i++) {
      int first, second, distance;
      cin >> first >> second >> distance;
      total += distance;
      streets[i] = make_pair(distance,
			     make_pair(first, second));
    }
    
    if (n == m+1){
      cout << 0 << endl;
      continue;
    }
      
    sort(streets.begin(), streets.end());

    parents.resize(m);
    for (int i=0; i<m; i++)
      parents[i] = i;
    ranks.assign(m, 0);

    int32_t cost=0;
    int num_edges = 0;
    for(int i=0; num_edges < m && i<n; i++){
      auto s = streets[i];
      int first = s.second.first, second = s.second.second;
      if (find_set(first) != find_set(second)){
	union_set(first, second);
	num_edges++;
	cost += s.first;
      }
    }
    cout << total-cost << endl;
    cin >> m >> n;
  }
  return 0;
}

int find_set(int id){
  if (parents[id] != id)
    parents[id] = find_set(parents[id]);
  return parents[id];
}

void union_set(int first, int second){
  first = find_set(first);
  second = find_set(second);
  if (ranks[first] > ranks[second])
    parents[second] = first;
  else if (ranks[second] > ranks[first])
    parents[first] = second;
  else {
    ranks[first] ++;
    parents[second] = first;
  }
}
