#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int main(void){
  int num_cases;
  cin >> num_cases;
  for (int case_cnt=0; case_cnt<num_cases; case_cnt++){
    int n, d;
    cin >> n >> d;
    vector<bool> st_big(n, false);
    vector<int> st_dist(n);
    for (int stone_cnt=0; stone_cnt<n; stone_cnt++){
      string stone;
      cin >> stone;
      st_types[stone_cnt] = (stone[0]=='B');
      st_dist[stone_cnt] = atoi(stone.substr(2).c_str());
    }
    //improvement: do this online
    bool in_small = false;
    int dist;
    int max_dist = 0;
    for (int stone_cnt=0; stone_cnt<n; stone_cnt++){
      if (!in_small && st_type[stone_cnt]){
	max_dist = max(max_dist, st_dist[stone_cnt]);
      }
      if (in_small && st_types[stone_cnt]) {
	in_small = false;
	dist = max(dist, st_dist[stone_cnt] - st_dist[stone_cnt-1]);
	max_dist = max(dist, max_dist);
	dist = 0;
      }
      if (!in_small && 
    }
    cout << endl;
  }
  return 0;
}
