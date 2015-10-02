#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

vector<int> next;
vector<int> visited;
vector<int> reach_count;
vector<int> in_loop;

void dfs(int node);

int main(void) {
  int T;
  cin >> T;
  for (int case_cnt=1; case_cnt <= T; case_cnt++) {
    next.clear();
    visited.clear();
    reach_count.clear();
    in_loop.clear();

    int N;
    cin >> N;
    next.resize(N);
    visited.resize(N);
    reach_count.resize(N);
    in_loop.resize(N);
    for (int node_cnt =0; node_cnt < N; node_cnt++) {
      int first, second;
      cin >> first >> second;
      next[first-1] = second-1;
    }

    for (int node_cnt =0; node_cnt < N; node_cnt++) 
      if (!reach_count[node_cnt]) 
	  dfs(node_cnt);

    int best_node = -1;
    int best_count = -1;
    for (int cnt=0; cnt < N; cnt++) 
      if (reach_count[cnt] > best_count) {
	best_node = cnt;
	best_count = reach_count[cnt];
      }
    
    cout << "Case " << case_cnt << ": " << best_node + 1 << endl;
  }
  return 0;
}

void dfs(int node) {
  if (reach_count[next[node]]) {
    reach_count[node] = reach_count[next[node]] + 1;
    return;
  }
    
  visited[node] = 1;
  int next_node = next[node];
  if (!visited[next_node]) {
    dfs(next_node);
    if (!in_loop[node]) 
      reach_count[node] = reach_count[next_node] + 1;
  }

  // When there is a loop
  else {
    int cnt = 1;
    in_loop[node] = 1;
    int current_node = next[node];
    while (current_node != node) {
      in_loop[current_node] = 1;
      cnt++;
      current_node = next[current_node];
    }

    reach_count[node] = cnt;
    current_node = next[node];
    while (current_node != node)
      {
	reach_count[current_node] = cnt;
	current_node = next[current_node];
      }
  }
  visited[node] = 0;
}


