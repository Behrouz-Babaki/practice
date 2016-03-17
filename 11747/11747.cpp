#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::make_pair;
using std::vector;

#define iii pair<pair<int, int> , int>

int find_set(int);
void union_set(int, int);

vector<int> parents;
vector<int> ranks;

int main(void){
  int num_nodes, num_edges;
  cin >> num_nodes >> num_edges;
  while (num_nodes && num_edges) {
    vector<iii> edges(num_edges);
    for (int i=0; i<num_edges; i++) {
      int weight, first, second;
      cin >> weight >> first >> second;
      edges[i] = make_pair(make_pair(first, second),
			   weight);
    }
    if (num_edges == num_nodes-1) {
      cout << "forest" << endl;
      continue;
    }
    sort(edges.begin(), edges.end());
    vector<bool> in_tree(num_edges, false);

    parents.resize(num_nodes);
    for (int i=0; i<num_nodes; i++)
      parents[i] = i;
    ranks.assign(num_nodes, 0);

    int tree_edges = 0;
    for (int i=0; tree_edges<num_nodes && i<num_edges; i++) {
      int weight, first, second;
      weight = edges[i].second;
      first = edges[i].first.first;
      second = edges[i].first.second;
      if (find_set(first) != find_set(second)){
	union_set(first, second);
	tree_edges++;
	in_tree[i] = true;
      }
    }
    vector<int> out_weights;
    int k=0;
    for (int i=0; i<num_edges; i++)
      if (!in_tree[i])
	out_weights.push_back(edges[i].second);
    sort(out_weights.begin(), out_weights.end());
    for (auto o : out_weights)
      cout << o << " ";
    cout << endl;
    cin >> num_nodes >> num_edges;
  }
}

int find_set(int id){
  if (id != parents[id])
    parents[id] = find_set(parents[id]);
  return parents[id];
}

void union_set(int first, int second) {
  first = find_set(first);
  second = find_set(second);
  if (ranks[first] > ranks[second])
    parents[first] = second;
  else if (ranks[second] > ranks[first])
    parents[second] = first;
  else {
    parents[second] = first;
    ranks[first] ++;
  }
}
