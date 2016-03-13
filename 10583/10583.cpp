#include <iostream>
#include <vector>

using std::cin;
using std::endl;
using std::cout;
using std::vector;

vector<vector<int> > graph;
vector<bool> visited;
void dfs(int);
int main(void) {
  int case_cnt = 1;
  int n, m;
  cin >> n >> m;
  while (n && m) {
    graph.clear();
    graph.resize(n);
    visited.assign(n, false);
    for (int i=0; i<m; i++){
      int first, second;
      cin >> first >> second;
      graph[first-1].push_back(second-1);
      graph[second-1].push_back(first-1);
    }
    int num_components = 0;
    for (int i=0; i<n; i++)
      if (!visited[i]) {
	num_components++;
	dfs(i);
      }
    cout << "Case " << case_cnt++ << ": " << num_components << endl;
    cin >> n >> m;
  }
  return 0;
}

void dfs(int node) {
  visited[node] = true;
  for (auto v : graph[node])
    if (!visited[v])
      dfs(v);
}
