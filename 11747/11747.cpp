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

#define iii pair<int, pair<int, int> >

int find_set(int);
void union_set(int, int);

vector<int> parents;
vector<int> ranks;

int main(void){
  int num_nodes, num_edges;
  cin >> num_nodes >> num_edges;
  while (num_nodes || num_edges) {
    vector<iii> edges(num_edges);
    for (int i=0; i<num_edges; i++) {
      int weight, first, second;
      cin >> first >> second >> weight;
      edges[i] = make_pair(weight, make_pair(first, second));
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
      weight = edges[i].first;
      first = edges[i].second.first;
      second = edges[i].second.second;
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
	out_weights.push_back(edges[i].first);
    sort(out_weights.begin(), out_weights.end());
    if (out_weights.size() == 0)
      cout << "forest";
    for (int i=0, s=out_weights.size(); i<s; i++){
      if (i) cout << " ";
      cout << out_weights[i];
    }
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
