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

int main(void) {
  int num_beverages;
  int case_cnt = 1;
  while (cin >> num_beverages) {
    vector<vector<int> > graph;
    graph.resize(num_beverages);
    
    map<string, int> b_ids;
    vector<string> b_names(num_beverages);
    for (int b_cnt=0; b_cnt<num_beverages; b_cnt++) {
      string name;
      cin >> name;
      b_ids[name] = b_cnt;
      b_names[b_cnt] = name;
    }

    int num_edges;
    cin >> num_edges;
    for (int edge_cnt=0; edge_cnt<num_edges; edge_cnt++) {
      string first, second;
      cin >> first >> second;
      int first_node, second_node;
      first_node = b_ids[first];
      second_node = b_ids[second];
      graph[first_node].push_back(second_node);
    }
    
    vector<int> in_edges(num_beverages, 0);
    for (int node_cnt=0; node_cnt<num_beverages; node_cnt++)
      for (auto second : graph[node_cnt])
	in_edges[second]++;

    vector<int> sorted(num_beverages, 0);
    int sort_id = 0;
    vector<int> visited(num_beverages, 0);
    while (sort_id < num_beverages) {
      int remove_id = 0;
      while(in_edges[remove_id] || visited[remove_id])
	remove_id++;
      sorted[sort_id++] = remove_id;
      visited[remove_id] = 1;
      for (auto second : graph[remove_id])
	in_edges[second]--;
    }
    

    cout << "Case #" << case_cnt << ": Dilbert should drink beverages in this order:";
    for (auto node_cnt : sorted)
      cout << " " << b_names[node_cnt];
    cout <<  "." << endl << endl;
    
    case_cnt++;
  }
  return 0;
}

