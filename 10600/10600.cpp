#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using std::cin;
using std::endl;
using std::cout;
using std::vector;
using std::pair;
using std::make_pair;
using std::sort;

#define ii pair<int, int>
#define iii pair<int, pair<int, int> >
#define viii vector<iii>

vector<int> parents;
vector<int> ranks;
int num_schools;

int find_set(int);
void union_set(int, int);
int compute_cost(const viii &, int, int);

int main(void){
  int num_cases;
  cin >> num_cases;
  while (num_cases--) {
    int num_connections;
    cin >> num_schools >> num_connections;
    viii connections(num_connections);
    for (int i=0; i<num_connections; i++){
      int first, second, cost;
      cin >> first >> second >> cost;
      connections[i] = make_pair(cost, make_pair(first-1, second-1));
    }
    sort(connections.begin(), connections.end());
    parents.resize(num_schools);
    for (int i=0; i<num_schools; i++)
      parents[i] = i;
    ranks.assign(num_schools, 0);

    vector<ii> edges(num_schools-1);
    int num_edges = 0;
    int total_cost=0;
    for (int i=0, s=connections.size(); num_edges<(num_schools-1) && i<s; i++) {
      int first, second, cost;
      cost = connections[i].first;
      first = connections[i].second.first;
      second = connections[i].second.second;
      if (find_set(first)!=find_set(second))  {
	union_set(first, second);
	edges[num_edges] = make_pair(first, second);
	num_edges++;
	total_cost += cost;
      }
    }


    int second_best;
    bool first = true;
    for (int i=0; i<(num_schools-1); i++) {
      int temp = compute_cost(connections, edges[i].first, edges[i].second);
      if (temp < 0)
	continue;

      if (first) {
	first = false;
	second_best = temp;
      }
      else if (temp < second_best)
	second_best = temp;
    }
    cout << total_cost << " " << second_best << endl;
  }
  return 0;
}

int find_set(int id) {
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
    parents[first] = second;
  }
}

int compute_cost(const viii & connections, int i1, int i2) {
  parents.resize(num_schools);
  for (int i=0; i<num_schools; i++)
    parents[i] = i;
  ranks.assign(num_schools, 0);

  int num_edges = 0;
  int total_cost=0;
  for (int i=0, s=connections.size(); num_edges<(num_schools-1) && i<s; i++) {
    int first, second, cost;
    cost = connections[i].first;
    first = connections[i].second.first;
    second = connections[i].second.second;
    if (find_set(first)!=find_set(second) &&
	(!(first==i1 && second==i2)) && 
	(!(first==i2 && second==i1))) {
      union_set(first, second);
      num_edges++;
      total_cost += cost;
    }
  }
  if (num_edges == num_schools-1)
    return total_cost;
  else
    return -1;
}

