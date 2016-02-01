#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::pair;
using std::make_pair;
using std::sort;
using std::min;

vector<vector<int> > graph;
vector<int> dfs_num;
vector<int> dfs_low;
vector<int> parent;
vector<pair<int, int> > num_comp;
int num_stations;
int num_bombed;
int root;
int r_children;
int dfs_counter;

void dfs_ap(int);

int main(void) {
  cin >> num_stations >> num_bombed;
  while (num_stations || num_bombed) {
    graph.clear();
    graph.resize(num_stations);
    dfs_low.clear();
    dfs_low.resize(num_stations, -1);
    dfs_num.clear();
    dfs_num.resize(num_stations, -1);
    parent.clear();
    parent.resize(num_stations, -1);
    num_comp.clear();

    //reading the graph
    int first, second;
    cin >> first >> second;
    while (first >= 0 && second >= 0) {
      graph[first].push_back(second);
      graph[second].push_back(first);
      cin >> first >> second;
    }
    
    dfs_counter = 0;
    for (int cnt=0; cnt < num_stations; cnt++)
      if (dfs_num[cnt] < 0) {
	root = cnt;
	r_children = 0;
	dfs_ap(cnt);
	num_comp.push_back(make_pair(cnt, r_children));
      }

    sort(num_comp.begin(), num_comp.end(),
	 [](const pair<int, int> &a, const pair<int, int>& b) {
	   if (a.second != b.second) return (a.second > b.second); 
	   else return (a.first < b.first);
	 });
    for (int cnt=0; cnt<num_bombed; cnt++)
      cout << num_comp[cnt].first << " " << num_comp[cnt].second << endl;
    cout << endl;

    cin >> num_stations >> num_bombed;
  }
  return 0;
}

void dfs_ap(int v) {

  dfs_num[v] = dfs_counter;
  dfs_low[v] = dfs_counter;
  dfs_counter++;
  
  int components = 1;
  for (auto u : graph[v]) {
    if (dfs_num[u] < 0) {
      if (v==root)
	r_children++;

      parent[u] = v;
      dfs_ap(u);

      if (v!= root && dfs_low[u] >= dfs_num[v])
	components++;

      dfs_low[v] = min(dfs_low[v], dfs_low[u]);
    }
    else if (u != parent[v])
      dfs_low[v] = min(dfs_low[v], dfs_num[u]);
  }

  num_comp.push_back(make_pair(v, components));
}
