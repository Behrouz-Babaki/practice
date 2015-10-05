#include <vector>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

vector<vector<int> > graph;
vector<int> order;
vector<int> visited;

void dfs(int node);

int main(void) {
  int n, m;
  cin >> n >> m;
  while (n) {
    graph.clear();
    graph.resize(n);
    order.clear();
    visited.clear();
    visited.resize(n, 0);

    for (int edge_cnt = 0; edge_cnt < m; edge_cnt++) {
      int first, second;
      cin >> first >> second;
      graph[first-1].push_back(second-1);
    }
    
    for (int node_cnt=0; node_cnt < n; node_cnt++)
      if (!visited[node_cnt])
	dfs(node_cnt);
    
    for (int node_cnt=order.size()-1; node_cnt>=0; node_cnt--)
       cout << order[node_cnt]+1 << " ";
    cout << endl;
    cin >> n >> m;
  }
  return 0;
}

void dfs(int node) {
  visited[node] = 1;

  for (auto next : graph[node])
    if (!visited[next])
      dfs(next);

  order.push_back(node);
}
