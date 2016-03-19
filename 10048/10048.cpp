#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstdlib>

using std::cout;
using std::endl;
using std::cin;
using std::sort;
using std::pair;
using std::make_pair;
using std::vector;
using std::max;

#define viii vector<pair<int, pair<int, int> > > 

int find_set(int);
void union_set(int, int);
int find_cost(int parent, int current, int target, int cost);
vector<int> parents;
vector<int> ranks;
vector<vector<pair<int, int> > > graph;

int main(void) {
  int num_crossings, num_streets, num_queries;
  cin >> num_crossings >> num_streets >> num_queries;
  int case_cnt = 1;
  bool first = true;

  while (num_crossings || num_streets || num_queries) {
  viii streets(num_streets);
    for (int i=0; i<num_streets; i++) {
      int c1, c2, d;
      cin >> c1 >> c2 >> d;
      streets[i] = make_pair(d, 
			     make_pair(c1-1, c2-1));
    }

    sort(streets.begin(), streets.end());

    parents.resize(num_crossings);
    for (int i=0; i<num_crossings; i++)
      parents[i] = i;
    ranks.assign(num_crossings, 0);
    
    graph.clear();
    graph.resize(num_crossings);
    int num_edges = 0;
    for (int i=0, s=streets.size(); num_edges < (num_crossings-1) && i<s; i++) {
      int c1, c2, d;
      d = streets[i].first;
      c1 = streets[i].second.first, c2 = streets[i].second.second;
      if (find_set(c1) != find_set(c2)) {
	union_set(c1, c2);
	num_edges++;
	graph[c1].push_back(make_pair(c2, d));
	graph[c2].push_back(make_pair(c1, d));
      }
    }

    if (first)
      first = false;
    else
      cout << endl;
    cout << "Case #" << case_cnt++ << endl;
    for(int i=0; i<num_queries; i++) {
      int first, second;
      cin >> first >> second;
      first--, second--;
      int cost = find_cost(-1, first, second, 0);
      if (cost < 0)
	cout << "no path" << endl;
      else
	cout << cost << endl;
    }
    cin >> num_crossings >> num_streets >> num_queries;
  }
  return 0;
}

int find_cost(int parent, int current, int target, int cost) {
  if (current == target)
    return cost;
  int c = -1;
  bool found = false;
  for (auto v : graph[current]) 
    if (v.first != parent) {
      int c2 = find_cost(current, v.first, target, max(cost,v.second));
      if (c2 > 0) {
	if (found)
	  c = max(c, c2);
	else {
	  found = true;
	  c = c2;
	}
      }
    }
  return c;
}

int find_set(int id){
  if (parents[id] != id)
    parents[id] = find_set(parents[id]);
  return parents[id];
}
void union_set(int first, int second){
  first = find_set(first);
  second = find_set(second);
  if (ranks[first] < ranks[second])
    parents[first] = second;
  else if (ranks[second] < ranks[first])
    parents[second] = first;
  else{
    ranks[first]++;
    parents[second] = first;
  }
}
