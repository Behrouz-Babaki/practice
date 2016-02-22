#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::map;
using std::set;
using std::ws;
using std::min;

class name_str {
public:
  string _name;
  string _surname;
  name_str() {}
  name_str(string name, string surname) : _name(name), _surname(surname) {}
  bool operator<(const name_str& right) const{
    if (_name != right._name)
      return (_name < right._name);
    return (_surname < right._surname);
  }
};

vector<set<int> > graph;
map<name_str, int> name_map;
vector<name_str> num_map;
vector<int> dfs_num;
vector<int> dfs_low;
vector<int> visited;
vector<int> S;
int num;
int scc_count;

void print_graph();
void dfs_scc(int);

int main(void){
  int p, t;
  cin >> p >> t >> ws;
  while (p) {
    string name, surname;
    graph.clear();
    graph.resize(p);
    name_map.clear();
    num_map.clear();
    num_map.resize(p);
    S.clear();
    dfs_num.assign(p, -1);
    dfs_low.assign(p, -1);
    visited.assign(p, 0);
    num = 0;
    scc_count = 0;

    for (int cnt=0; cnt < p; cnt++) {
      cin >> name >> surname >> ws;
      name.pop_back();
      name_str name_surname(name, surname);
      int id = name_map.size();
      name_map[name_surname] = id;
      num_map[id] = name_surname;
    }

    for(int cnt=0; cnt < t; cnt++) {
      cin >> name >> surname >> ws;
      name.pop_back();
      name_str first(name, surname);
      
      cin >> name >> surname >> ws;
      name.pop_back();
      name_str second(name, surname);
      int first_id, second_id;
      first_id = name_map[first];
      second_id = name_map[second];
      graph[first_id].insert(second_id);
    }

    for (int cnt=0, size = graph.size(); cnt<size; cnt++)
      if (dfs_num[cnt] < 0)
	dfs_scc(cnt);

    cout << scc_count << endl;
    cin >> p >> t >> ws;
  }
  return 0;
}


void dfs_scc(int node) {
  dfs_num[node] = dfs_low[node] = num;
  num++;
  visited[node] = 1;
  S.push_back(node);
  for (auto v : graph[node]) {
    if (dfs_num[v]<0)
      dfs_scc(v);
    if (visited[v])
      dfs_low[node] = min(dfs_low[node], dfs_low[v]);
  }
  
  if (dfs_num[node] == dfs_low[node]) {
    int id;
    do {
      id = S.back();
      visited[id] = 0;
      S.pop_back();
    }while (id!=node);
    scc_count++;
  }
  
}

void print_graph(){
  cout << "trust relations:" << endl;
  for (int i=0, s=graph.size(); i<s; i++) {
    name_str first = num_map[i];
    cout << first._name << "-" << first._surname << " trusts:" << endl;
    for (auto j : graph[i]) {
      name_str second = num_map[j];
      cout << second._name << "-" << second._surname << "\t";
    }
    cout << endl;
  }
}
