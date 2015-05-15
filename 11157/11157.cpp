#include <iostream>
#include <vector>
#include <string>
#include <utility>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::max;

int main(void){
  int num_cases;
  cin >> num_cases;
  for (int case_cnt=0; case_cnt<num_cases; case_cnt++){
    int n, d;
    cin >> n >> d;

    int max_dist = 0, prev = 0, prev2=0, current = 0;
    bool isbig;
    for (int stone_cnt=0; stone_cnt<=n; stone_cnt++){
      if (stone_cnt < n) {
      string stone;
      cin >> stone;
      isbig = (stone[0]=='B');
      current = atoi(stone.substr(2).c_str()); 
      }
      else {
	isbig = true;
	current = d;
      }
      max_dist = max(max_dist, current-prev2);
      prev2 = prev;
      prev = current;
      if (isbig)
	prev2 = current;
    }
    cout << "Case " << case_cnt+1 << ": " << max_dist << endl;
  }
  return 0;
}
