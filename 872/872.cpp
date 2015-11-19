#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>

using std::cin;
using std::ws;
using std::cout;
using std::endl;
using std::string;
using std::getline;
using std::istringstream;
using std::vector;
using std::map;
using std::sort;

map<char,int> var_to_num;
vector<char> vars;
vector<char> old_vars;
vector<vector<int> > graph;
vector<int> in_degree;
vector<bool> visited;
vector<char> order;
bool found;

void print(int position,
	   vector<int> in_degree);

int main(void) {
  int num_cases;
  cin >> num_cases >> ws;
  while (num_cases--) {

    var_to_num.clear();
    old_vars.clear();
    vars.clear();
    graph.clear();
    in_degree.clear();
    order.clear();
    visited.clear();

    string line;
    getline(cin, line);
    istringstream ss(line);

    char ch;
    while (ss >> ch) {
      vars.push_back(ch);
      var_to_num[ch] = vars.size()-1;
    }
    
    old_vars = vars;
    sort(vars.begin(), vars.end());
    graph.resize(vars.size());
    in_degree.resize(vars.size(), 0);

    
    getline(cin, line);
    ss.clear();
    ss.str(line);
    string cons;
    while (ss >> cons) {
      char first = var_to_num[cons[0]], 
	second = var_to_num[cons[2]];
      graph[first].push_back(second);
      in_degree[second]++;
    }

    visited.resize(vars.size(), false);
    order.resize(vars.size());
    found = false;
    print(0, in_degree);
    if (!found)
      cout << "NO" << endl;
    if (num_cases)
      cout << endl;
    cin >> ws;
  }
  return 0;
}

  
void print(int position,
	   vector<int> in_degree) {

  if (position == vars.size()) {
    found = true;
    for (int cnt=0; cnt < vars.size()-1; cnt++)
      cout << order[cnt] << " ";
    cout << order.back() << endl;
    return;
  }
  
  vector<int> heads;
  for (int index=0; index<vars.size(); index++) {
  int node_num = var_to_num[vars[index]];
  if (!in_degree[node_num] && !visited[node_num]) 
    heads.push_back(node_num);
  }
  
  for (auto head : heads) {
      order[position] = old_vars[head];
      vector<int> in_degree2(in_degree);
      for (auto neighbour : graph[head])
	in_degree2[neighbour]--;
      visited[head] = true;
      print(position+1, in_degree2);
      visited[head] = false;
  }

}
