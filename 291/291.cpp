#include <iostream>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::make_pair;
using std::vector;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define TRvii(c,it)						\
  for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvi(c,it)						\
  for (vi::iterator it = (c).begin(); it != (c).end(); it++)

void backtrack (int nodeId, int nodeCounter, vi partial, vector<vii> graph);
void print_graph (vector<vii> graph);

int main (void) {
  int first []  = {1, 1, 1, 2, 2, 3, 3, 4};
  int second [] = {2, 3, 5, 3, 5, 4, 5, 5};
  vector<vii> graph (5);
  for (int cnt = 0; cnt < 8; cnt++) {
    int node1 = first[cnt] - 1;
    int node2 = second[cnt] - 1;
    graph[node1].push_back(make_pair(node2,1));
    graph[node2].push_back(make_pair(node1,1));
  }
  // print_graph(graph);
  vector<int> partial;
  partial.push_back(0);
  backtrack (0, 0, partial, graph);
    
  return 0;
}

void print_graph (vector<vii> graph) {
  for (int id = 0; id < graph.size(); id++) {
    cout << id+1 << ":" << endl;
    TRvii (graph[id], it) 
      cout << it->first + 1 << ":" << it->second << "\t";
    cout << endl;
  }
}

void backtrack (int nodeId, int nodeCounter, vi partial, vector<vii> graph) {
  
  if (nodeCounter == 8){
    TRvi (partial, it)
      cout << *it + 1;
    cout << endl;
    return;
  }

  TRvii (graph[nodeId], it)
    if (it->second) {
      it->second = 0;
      int otherIndex = 0;
      TRvii (graph[it->first], it2) {
	if (it2->first == nodeId) {
	  it2->second = 0;
	  break;
	}
	otherIndex++;
      }
      partial.push_back(it->first);
      backtrack(it->first, nodeCounter+1, partial, graph);
      partial.pop_back();
      graph[it->first][otherIndex].second = 1;
      it->second = 1;
    }

}
