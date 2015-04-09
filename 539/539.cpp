#include <iostream>
#include <vector>
#include <set>
#include <utility>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::set;
using std::make_pair;
using std::pair;

int best;
vector<vector<int> > graph;
void search(int node, set<pair<int,int> > used, int length);

int main(void) {
  int nodes, edges;
  cin >> nodes >> edges;
  while (nodes && edges) {
    graph.clear();
    graph.resize(nodes);
    while (edges--) {
      int tail, head;
      cin >> tail >> head;
      graph[tail].push_back(head);
      graph[head].push_back(tail);
    }
    best = 0;
    for (int i=0; i<nodes; i++) {
      set<pair<int,int> > used;
      search(i,used, 0);
    }
    cout << best << endl;
    cin >> nodes >> edges;
  }
  return 0;
}

void search(int node, set<pair<int,int> > used, int length){
  if (length > best) 
    best = length;
    
  for (auto other:graph[node]) {
    bool valid = true;
    for (set<pair<int,int> >::iterator itr = used.begin(), end = used.end();
	 valid && itr!=end; itr++)
      if ((itr->first == node && itr->second == other) ||
	  (itr->first == other && itr->second == node))
	valid = false;
    if (valid) {
      used.insert(make_pair(node,other));
      search(other, used, length+1);
      used.erase(used.find(make_pair(node,other)));
    }
  }
}
