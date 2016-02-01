#include <vector>
#include <iostream>
#include <cstdlib>
#include <string>
#include <utility>
#include <cstdlib>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::ws;
using std::vector;
using std::string;
using std::pair;
using std::make_pair;
using std::min;
using std::sort;

vector<vector<int> > graph;
vector<int> dfs_num;
vector<int> dfs_low;
vector<int> parent;
vector<pair<int, int> > bridges;
int dfs_counter;

void dfs_ap (int);

int main(void) {
  int num_vertices;
  while (cin >> num_vertices) {
    graph.clear();
    graph.resize(num_vertices);
    dfs_low.clear();
    dfs_low.resize(num_vertices, -1);
    dfs_num.clear();
    dfs_num.resize(num_vertices, -1);
    parent.clear();
    parent.resize(num_vertices, -1);
    bridges.clear();

    dfs_counter = 0;

    // reading the graph
    for (int vertex_cnt=0; vertex_cnt < num_vertices; vertex_cnt++) {
      int vertex;
      cin >> vertex;
      string str;
      cin >> str;
      string str2(str, 1, str.length()-2);
      int num_edges = atoi(str2.c_str());
      for (int v2_cnt=0; v2_cnt < num_edges; v2_cnt++) {
	int v2; 
	cin >> v2;
	graph[vertex].push_back(v2);
	graph[v2].push_back(vertex);
      }
    }

    for (int v_cnt=0; v_cnt < num_vertices; v_cnt++) {
      if (dfs_num[v_cnt]<0) 
	dfs_ap(v_cnt);


    }

    // printing the bridges
    cout << bridges.size() << " critical links" << endl;
    sort(bridges.begin(), bridges.end());
    for (auto bridge : bridges)
      cout << bridge.first << " - " << bridge.second << endl;
    cout << endl;
  }

  return 0;
}

void dfs_ap(int vertex) {
  dfs_num[vertex] = dfs_counter;
  dfs_low[vertex] = dfs_counter;
  dfs_counter++;

  for (auto u : graph[vertex]) 
    if (dfs_num[u] < 0) {
      parent[u] = vertex;
      dfs_ap(u);
      if (dfs_low[u] > dfs_num[vertex]){
	pair<int,int> edge = 
	  u < vertex ? make_pair(u, vertex) : make_pair(vertex, u);
	bridges.push_back(edge);
      }
      dfs_low[vertex] = min(dfs_low[u], dfs_low[vertex]);
    }
    else if (u != parent[vertex])
      dfs_low[vertex] = min(dfs_low[vertex], dfs_num[u]);
}

