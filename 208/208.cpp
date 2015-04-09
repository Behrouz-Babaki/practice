#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::set;
using std::sort;


int sol_cnt;
vector<vector<int> > graph;
void search(vector<int> prev, set<int> prev_set, int node, int fire);

int main(void) {

  int fire;
  int case_cnt = 1;
  while (cin >> fire) {
    cout << "CASE " << case_cnt++ << ":" << endl;
    fire--;
    sol_cnt = 0;
    graph.clear();
    int first, second;
    cin >> first >> second;
    while (first && second) {
      if(graph.size() < first)
	graph.resize(first);
      if (graph.size() < second)
	graph.resize(second);
      first--, second--;
      graph[first].push_back(second);
      graph[second].push_back(first);
      cin >> first >> second;
    }

    for (int i=0; i<graph.size();i++)
      sort(graph[i].begin(), graph[i].end());

    vector<int> prev;
    set<int> prev_set;
    search(prev, prev_set, 0, fire);
    cout << "There are "<< sol_cnt <<" routes from the firestation to streetcorner "<<fire+1<<"." << endl;
  }
  return 0;
}

void search(vector<int> prev, set<int> prev_set, int node, int fire) {
  if (node == fire) {
    sol_cnt++;
    for(auto n : prev)
      cout << n+1 << " ";
    cout << fire+1 << endl;
    return;
  }
  prev.push_back(node);
  prev_set.insert(node);
  for (auto next : graph[node]){
    if (prev_set.find(next)==prev_set.end())
      search(prev, prev_set, next, fire);
  }
}
