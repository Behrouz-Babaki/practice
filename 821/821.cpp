#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::map;
using std::min;

int main(void) {
  int first, second;
  int case_cnt = 1;
  cin >> first >> second;
  while (first && second) {
    vector<vector<int> > graph;
    map<int, int> val_map;
    while (first && second) {

      if (val_map.find(first)==val_map.end()) {
	int s = val_map.size();
	val_map[first] = s;
	vector<int> new_vec;
	graph.push_back(new_vec);
      }
      if (val_map.find(second)==val_map.end()) {
	int s = val_map.size();
	val_map[second] = s;
	vector<int> new_vec;
	graph.push_back(new_vec);
      }

      int f, s;      
      f = val_map[first], s = val_map[second];
      graph[f].push_back(s);

      cin >> first >> second;
    }
    int num_nodes = val_map.size();
    vector<vector<int> > adjmat(num_nodes, vector<int>(num_nodes, num_nodes*2));
    for (int i=0; i<graph.size(); i++)
      adjmat[i][i] = 0;

    for (int i=0; i<graph.size(); i++)
      for (auto j : graph[i])
	adjmat[i][j] = 1;
    
    for (int k=0; k<num_nodes; k++)
      for (int i=0; i<num_nodes; i++)
	for (int j=0; j<num_nodes; j++)
	  adjmat[i][j] = min(adjmat[i][j], adjmat[i][k]+adjmat[k][j]);

    double total = 0;
    for (int i=0; i<num_nodes; i++)
      for (int j=0; j<num_nodes; j++)
	if (adjmat[i][j] < num_nodes*2)
	  total += adjmat[i][j];
    printf("Case %d: average length between pages = %.3f clicks\n", case_cnt, total / (num_nodes*(num_nodes-1)));
    case_cnt++;
    cin >> first >> second;
  }
  return 0;
}
