#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::map;
using std::set;
using std::ws;

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

vector<vector<int> > graph;
map<name_str, int> name_map;
vector<name_str> num_map;

void print_graph();

int main(void){
  int p, t;
  cin >> p >> t >> ws;
  while (p && t) {
    string name, surname;
    graph.clear();
    graph.resize(p);
    name_map.clear();
    num_map.clear();
    num_map.resize(p);

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
      graph[first_id].push_back(second_id);
    }


    cin >> p >> t >> ws;
  }
  return 0;
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
