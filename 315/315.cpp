#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <sstream>

using std::cout;
using std::endl;
using std::cin;
using std::ws;
using std::istringstream;
using std::vector;
using std::set;
using std::string;

typedef set<size_t> st;
typedef vector<st> vst;
typedef vector<size_t> vt;
typedef vector<int> vi;

#define TRvst(c, it) \
  for (vst::iterator it = (c).begin(), eit = (c).end(); it != eit; it++)

#define TRst(c, it) \
  for (st::iterator it = (c).begin(), eit = (c).end(); it != eit; it++)

size_t N;
vst graph;
vi dfs_num, dfs_low;

void print_graph();
void flood_fill (size_t u, size_t num);

int main(void) {
  cin >> N >> ws;
  string line;
  istringstream ss;
  size_t node1, node2;
  while (N > 0) {
    dfs_num.clear();
    dfs_num.resize(N, -1);
    dfs_low.clear();
    dfs_low.resize(N, -1);
    graph.clear();
    graph.resize(N, st());

    bool finished = false;
    while (!finished) {
      getline(cin, line);
      ss.clear();
      ss.str(line);
      ss >> node1;
      if (node1)  {
	ss >> node2;
	while (!ss.fail()) {
	  graph[node1-1].insert(node2-1);
	  graph[node2-1].insert(node1-1);
	  ss >> node2;
	}
      }
      else
	finished = true;
    }

    size_t ap_cnt = 0;
    for (size_t node_cnt = 0; node_cnt < N; node_cnt++)
      if (dfs_num[node_cnt] < 0) {
	if (graph[node_cnt].size() > 1)
	  ap_cnt++;
	flood_fill(node_cnt, 0);
      }

    for (size_t node_cnt = 0; node_cnt < N; node_cnt++)
      if (dfs_low[node_cnt] >= dfs_num[node_cnt])
	ap_cnt++;
    cout << ap_cnt << endl;
    cin >> N >> ws;
  }
  return 0;
}

void flood_fill (size_t u, size_t num){
  dfs_low[u] = dfs_num[u] = num;
  //cout << u << ":" << num << endl;
  TRst (graph[u], it)
    if (dfs_num[*it] < 0)
      flood_fill (*it, num+1);
    else if (dfs_num[*it] < dfs_low[u])
      dfs_low[u] = dfs_num[*it];
}

void print_graph() {
  cout << "----------------" << endl;
  size_t counter = 0;
  TRvst (graph, it1) {
    cout << counter++ << ": ";
    TRst (*it1, it2)
      cout << *it2 << " ";
    cout << endl;
  }
  cout << "----------------" << endl;
}
