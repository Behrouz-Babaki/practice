#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

vector<vector<int> > graph;
int num_stations;
int num_bombed;

int main(void) {
  cin >> num_stations >> num_bombed;
  while (num_stations || num_bombed) {
    graph.clear();
    graph.resize(num_stations);

    //reading the graph
    int first, second;
    cin >> first >> second;
    while (first >= 0 && second >= 0) {
      graph[first].push_back(second);
      graph[second].push_back(first);
      cin >> first >> second;
    }
    
    //TODO process the graph and print the output
    cin >> num_stations >> num_bombed;
  }
  return 0;
}

