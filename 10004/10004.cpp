#include <iostream>
#include <vector>
#include <set> 

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::set;

typedef vector<size_t> vs;
typedef vector<vs> vvs;

bool check(vvs graph, 
	   size_t node_number, 
	   size_t color_number);


int main(void) {
  size_t num_nodes;
  size_t num_edges;
  cin >> num_nodes;
  while (num_nodes) {
    vvs graph(num_nodes);
    cin >> num_edges;
    for (size_t edge_counter = 0; edge_counter < num_edges; edge_counter++) {
      size_t first, second;
      cin >> first >> second;
      graph[first].push_back(second);
      graph[second].push_back(first);
    }

    if (!check(graph, 0, 1) && !check(graph, 0, 2))
      cout << "NOT BICOLORABLE." << endl;
    else
      cout << "BICOLORABLE." << endl;
        
    cin >> num_nodes;
  }
  return 0;
}


bool check(vvs graph, 
	   size_t node_number, 
	   size_t color_number) {
  size_t num_nodes = graph.size();
  vector<size_t> colors(num_nodes, 0);
  bool fail = false;
  set<size_t> blue;
  set<size_t> red;
  if (color_number == 1) {
    blue.insert(node_number);
    colors[node_number] = 1;
  }

  if (color_number == 2) {
    red.insert(node_number);
    colors[node_number] = 2;
  }

  while (!fail && (!blue.empty() || !red.empty())) {
    set<size_t>::iterator it;
    set<size_t>* target;
    set<size_t>* orig;
    if (!blue.empty()) {
      it = blue.begin();
      target = &red;
      orig = &blue;
    }
    else {
      it = red.begin();
      target = &blue;
      orig = &red;
    }
    size_t node = *it;
    orig->erase(it);
    
    size_t target_color;
    if (colors[node] == 1) target_color = 2;
    if (colors[node] == 2) target_color = 1;

    for (size_t n_counter = 0; !fail && n_counter < graph[node].size(); n_counter++) {
      size_t n_num = graph[node][n_counter];
      if (colors[n_num] && colors[n_num] != target_color) 
	fail = true;
      else
	if (!colors[n_num]) {
	  colors[n_num] = target_color;
	  target->insert(n_num);
	}
    }
	
  }

  return !fail;
}
