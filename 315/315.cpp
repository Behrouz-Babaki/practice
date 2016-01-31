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
using std::min;

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
vi dfs_num, dfs_low, parent;
size_t t;
size_t ap_cnt;
size_t root;
size_t num_children;

void dfs_ap (size_t u);

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
    parent.clear();
    parent.resize(N, -1);
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

    ap_cnt = 0;
    for (size_t node_cnt = 0; node_cnt < N; node_cnt++)
      if (dfs_num[node_cnt] < 0) {
	root = node_cnt;
	num_children = 0;
	dfs_ap(node_cnt);
	ap_cnt += (num_children > 1);
      }


    cout << ap_cnt << endl;
    cin >> N >> ws;
  }
  return 0;
}

void dfs_ap (size_t u){
  bool ap = false;
  dfs_low[u] = t;
  dfs_num[u] = t;
  t++;
  TRst (graph[u], it) {
    if (dfs_num[*it] < 0) {
      parent[*it] = u;
      dfs_ap (*it);
      if (u == root)
	num_children++;
      if (u != root && dfs_low[*it] >= dfs_num[u])
	ap = true;
      dfs_low[u] = min(dfs_low[u], dfs_low[*it]);
    }
    else if (*it != parent[u]) {
      dfs_low[u] = min(dfs_low[u], dfs_num[*it]);
    }
  }
  if (ap) 
    ap_cnt++;
}


