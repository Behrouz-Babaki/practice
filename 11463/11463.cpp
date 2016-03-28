#include <iostream>
#include <cstdlib>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::max;

int main(void) {
  int num_cases;
  cin >> num_cases;
  for (int case_cnt=0; case_cnt < num_cases; case_cnt++) {
    int num_nodes, num_edges;
    cin >> num_nodes >> num_edges;
    vector<vector<int> > graph(num_nodes, vector<int>(num_nodes, -1));
    int first, second;
    for (int i=0; i<num_edges; i++) {
      cin >> first >> second;
      graph[first][second] = 1;
      graph[second][first] = 1;
    }
    cin >> first >> second;
    for (int i=0; i<num_nodes; i++)
      graph[i][i] = 0;

    for (int k=0; k<num_nodes; k++)
      for (int i=0; i<num_nodes; i++)
	for (int j=0; j<num_nodes; j++) {
	  int sum = -1;
	  if (graph[i][k] >= 0 && graph[k][j] >= 0)
	    sum = graph[i][k] + graph[k][j];
	  if (graph[i][j] < 0)
	    graph[i][j] = sum;
	  else if (sum>=0 && graph[i][j] > sum)
	    graph[i][j] = sum;
	}

    int mx = 0;
    for (int i=0; i<num_nodes; i++)
      mx = max(mx, graph[first][i]+graph[i][second]);
    cout << "Case " << case_cnt+1 << ": " << mx << endl;
  }
  return 0;
}
