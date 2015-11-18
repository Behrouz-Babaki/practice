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
vector<vector<int> > graph;
vector<int> in_degree;
vector<int> order;

int main(void) {
  int num_cases;
  cin >> num_cases >> ws;
  while (num_cases--) {

    var_to_num.clear();
    vars.clear();
    graph.clear();
    in_degree.clear();
    order.clear();

    string line;
    getline(cin, line);
    istringstream ss(line);

    char ch;
    while (ss >> ch) {
      vars.push_back(ch);
      var_to_num[ch] = vars.size()-1;
    }
    
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

    //print_orders(-1);
    

    cin >> ws;
  }
  return 0;
}

void print_orders(int position){
  
}
