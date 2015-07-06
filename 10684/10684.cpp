#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::max_element;

int main(void) {
  int num_bets;
  cin >> num_bets;
  while (num_bets) {
    vector<int> bets(num_bets);
    for (int bet_cnt = 0; bet_cnt < num_bets; bet_cnt++)
      cin >> bets[bet_cnt];

    vector<int> best_vals(num_bets);
    for (int id = num_bets-1; id >=0 ; id--){
      best_vals[id] = bets[id];
      if (id < num_bets - 1 && best_vals[id+1] > 0)
	best_vals[id] += best_vals[id+1];
    }

    int best_val = * max_element(best_vals.begin(), best_vals.end());
    if (best_val > 0)
      cout << "The maximum winning streak is " << best_val << "." << endl;
    else
      cout << "Losing streak." << endl;

    cin >> num_bets;
  }
  return 0;
}
