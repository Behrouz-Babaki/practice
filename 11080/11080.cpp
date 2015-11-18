#include <iostream>
#include <vector>
#include <queue>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::queue;

int main(void) {
  int num_cases;
  cin >> num_cases;
  while (num_cases--) {
    int num_vertices, num_edges;
    cin >> num_vertices >> num_edges;
    vector<vector<int> > graph(num_vertices); 
    vector<int> colors(num_vertices, -1);

    int counts[2];
    int total = 0;

    for (int edge_counter=0; edge_counter<num_edges; edge_counter++) {
      int first, second;
      cin >> first >> second;
      graph[first].push_back(second);
      graph[second].push_back(first);
    }
    queue<int> q;
    bool conflict = false;
    for (int v_cnt=0; !conflict && v_cnt<num_vertices; v_cnt++) 
      if (colors[v_cnt]<0) {
	q.push(v_cnt);
	colors[v_cnt] = 0;
	counts[0] = 1;
	counts[1] = 0;
    	while (!conflict && !q.empty()) {
	  int current = q.front();
	  q.pop();
	  int color = 1 - colors[current];
	  for (auto v : graph[current]) 
	    if (colors[v] < 0) {
	      colors[v] = color;
	      counts[color]++;
	      q.push(v);
	    }
	    else if (colors[v] != color) 
	      conflict = true;
	}
	if (counts[0] == 1 && counts[1] == 0)
	  total++;
	else
	  total += (counts[0] > counts[1] ? counts[1] : counts[0]);
    }

    if (conflict)
      cout << -1;
    else
      cout << total;
    cout << endl;

  }
  return 0;
}
