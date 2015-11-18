#include <iostream>
#include <vector>
#include <queue>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::queue;

int main(void){
  int num_vertices;
  while (cin >> num_vertices && num_vertices > 0) {

    vector<vector<int> > graph(num_vertices);
    int first, second;
    while(cin >> first >> second && first && second) {
      graph[first-1].push_back(second-1);
      graph[second-1].push_back(first-1);
    }
    
    vector<int> colors(num_vertices, -1);
    bool conflict=false;
    for (int v_cnt=0; !conflict && v_cnt<num_vertices; v_cnt++)
      if (colors[v_cnt]<0) {
	colors[v_cnt]=0;
	queue<int> q;
	q.push(v_cnt);
	while (!conflict && !q.empty()) {
	  int current=q.front();
	  q.pop();
	  for (auto neighbor : graph[current])
	    if (colors[neighbor]<0) {
	      colors[neighbor]= 1-colors[current];
	      q.push(neighbor);
	    }
	    else if (colors[neighbor] == colors[current])
	      conflict = true;
	}
      }
    if (conflict)
      cout << "NO";
    else 
      cout << "YES";
    cout << endl;
    
  }
  return 0;
}
