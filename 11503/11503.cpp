#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::map;
using std::string;
using std::vector;

vector<int> parent;
vector<int> size;

void union_set(int id1, int id2);
int get_parent(int id);

int main(void) {
  int num_cases;
  cin >> num_cases;
  while (num_cases--) {
    parent.clear();
    size.clear();
    int num_friendships;
    cin >> num_friendships;
    map<string, int> name_map;
    for (int i=0; i<num_friendships; i++) {
      string names[2];
      int ids[2];
      cin >> names[0] >> names[1];
      for (int j=0; j<2; j++) {
	map<string,int>::iterator itr = name_map.find(names[j]);
	if (itr != name_map.end())
	  ids[j] = itr->second;
	else {
	  int new_id = name_map.size();
	  name_map[names[j]] = new_id;
	  ids[j] = new_id;
	  parent.push_back(new_id);
	  size.push_back(1);
	}
      }
      union_set(ids[0], ids[1]);
      cout << size[get_parent(ids[0])] << endl;
    }
  }
}

void union_set(int id1, int id2) {
  int p1 = get_parent(id1);
  int p2 = get_parent(id2);
  if (p1 != p2) {
    parent[p1] = p2;
    size[p2] += size[p1];
  }
}

int get_parent(int id) {
  if (parent[id] != id)
    parent[id] = get_parent(parent[id]);
  return parent[id];
}
