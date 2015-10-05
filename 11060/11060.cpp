#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::ws;
using std::vector;
using std::map;
using std::string;
using std::stringstream;

vector<vector<int> > graph;
vector<int> visited;
vector<int> order;

void dfs(int);

int main(void) {
  int num_beverages;
  int case_cnt = 1;
  while (cin >> num_beverages) {
    graph.clear();
    graph.resize(num_beverages);
    visited.clear();
    visited.resize(num_beverages, 0);
    order.clear();
    
    map<string, int> b_names;
    vector<string> b_ids(num_beverages);
    for (int b_cnt=0; b_cnt<num_beverages; b_cnt++) {
      string name;
      cin >> name;
      b_names[name] = b_cnt;
      b_ids[b_cnt] = name;
    }

    int num_edges;
    cin >> num_edges;
    for (int edge_cnt=0; edge_cnt<num_edges; edge_cnt++) {
      string first, second;
      cin >> first >> second;
      int first_node, second_node;
      first_node = b_names[first];
      second_node = b_names[second];
      graph[first_node].push_back(second_node);
    }
    
    for (int node_cnt=0; node_cnt<num_beverages; node_cnt++)
      if (!visited[node_cnt])
	dfs(node_cnt);

    cout << "Case #" << case_cnt << ": Dilbert should drink beverages in this order:";
    for (int node_cnt=order.size()-1; node_cnt>=0; node_cnt--)
      cout << " " << b_ids[order[node_cnt]];
    cout <<  "." << endl << endl;
    
    case_cnt++;
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
