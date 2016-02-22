#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::map;
using std::string;
using std::ws;
using std::set;
using std::min;

vector<set<int> > graph;
map<string,int> name_map;
vector<string> num_map;
vector<int> dfs_num;
vector<int> dfs_low;
vector<int> visited;
vector<int> S;
vector<vector<int> > comp_list;
int num;

void add_edge(string, string);
void print_graph();
void dfs_scc(int);

int main(void){
  int n_people, n_calls;
  string name1, name2;
  int n_ds = 1;
  cin >> n_people >> n_calls >> ws;
  while (n_people && n_calls) {

    graph.clear();
    graph.resize(n_people);
    name_map.clear();
    num_map.clear();
    num_map.resize(n_people);
    comp_list.clear();

    for (int call_cnt=0; call_cnt<n_calls; call_cnt++){
      cin >> name1 >> name2 >> ws;
      add_edge(name1, name2);
    }

    dfs_num.assign(n_people, -1);
    dfs_low.assign(n_people, -1);
    visited.assign(n_people, 0);
    S.clear();
    num = 0; 
    for (int cnt=0, size=graph.size(); cnt<size; cnt++)
      if (dfs_num[cnt]<0)
	dfs_scc(cnt);
    
    cout << "Calling circles for data set " << n_ds++ << ":" << endl;
    for (auto l : comp_list) {
      for (int i=0, s=l.size(); i<s; i++) {
	cout << num_map[l[i]];
	if (i<s-1)
	  cout << ", ";
      }
      cout << endl;
    }
      
    cin >> n_people >> n_calls >> ws;
    if (n_people && n_calls)
      cout << endl;
  }
  return 0;
}

void dfs_scc(int node){
  dfs_num[node] = num;
  dfs_low[node] = num;
  num ++; 
  S.push_back(node);
  visited[node] = 1;

  for (auto v : graph[node]){
    if (dfs_num[v] < 0)
      dfs_scc(v);
    if (visited[v]) // WHY???
      dfs_low[node] = min(dfs_low[node], dfs_low[v]);
  }

  if (dfs_low[node] == dfs_num[node]){
    vector<int> components;
    int v;
    do {
      v = S.back();
      visited[v] = 0; // WHY???
      components.push_back(v);
      S.pop_back();
     } while (v!=node);
    comp_list.push_back(components);
  }
}


void add_edge(string name1, string name2){
  map<string,int>::iterator it;
  string names[2] = {name1, name2};
  int ids[2];
  for (int i=0; i<2; i++) {
    it = name_map.find(names[i]);
    if (it == name_map.end()) {
      int id = name_map.size();
      name_map[names[i]] = id;
      num_map[id] = names[i];
      ids[i] = id;
    }
    else
      ids[i] = it->second;
  }
  
  int first = ids[0];
  int second = ids[1];
  if (graph[first].find(second)==graph[first].end())
    graph[first].insert(second);
  
}

void print_graph(){
  cout << "names:" << endl;
  for (auto n : name_map)
    cout << n.first << ":" << n.second << endl;

  for (int n=0, size=graph.size(); n<size; n++) {
    cout << n << ": ";
    for (auto d : graph[n])
      cout << d << "\t";
    cout << endl;
  }
}
