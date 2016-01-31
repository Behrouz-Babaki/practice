#include <vector>
#include <iostream>
#include <cstdlib>
#include <string>

using std::cin;
using std::cout;
using std::ws;
using std::vector;
using std::string;

int main(void) {
  int num_vertices;
  while (cin >> num_vertices) {
    vector<vector<int> > graph (num_vertices);
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
  }
  return 0;
}


