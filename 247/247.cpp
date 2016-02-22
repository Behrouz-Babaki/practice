#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::map;
using std::string;
using std::ws;
using std::set;

vector<set<int> > graph;
map<string,int> name_map;

void add_edge(string, string);
void print_graph();

int main(void){
  int n_people, n_calls;
  string name1, name2;

  cin >> n_people >> n_calls >> ws;
  while (n_people && n_calls) {

    graph.clear();
    graph.resize(n_people);
    name_map.clear();

    for (int call_cnt=0; call_cnt<n_calls; call_cnt++){
      cin >> name1 >> name2 >> ws;
      add_edge(name1, name2);
    }

    cin >> n_people >> n_calls >> ws;
  }
  return 0;
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
