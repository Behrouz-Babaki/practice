
#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::next_permutation;

int main(void) {
  int num_cases;
  cin >> num_cases;
  while (num_cases--) {
    int size;
    cin >> size;
    vector<vector<int> > grid(size, vector<int>(size));
    for (int i = 0; i < size; i++)
      for (int j = 0; j < size; j++)
	cin >> grid[i][j];
    vector<int> alice(size);
    for (int i = 0; i < size; i++)
      alice[i] = i;

    int best_gain;
    bool first = true;
    do {
      vector<bool> selected(size, false);
      int current_gain = 0;
      
      for (int alice_counter = 0; alice_counter < size; alice_counter++) {
	int best_bob;
	int best_bob_id;
	bool first_bob = true;
	for (int bob_counter = 0; bob_counter < size; bob_counter++)
	  if (!selected[bob_counter]) {
	    int val = grid[alice[alice_counter]][bob_counter];
	    if (first_bob) {
	      best_bob_id = bob_counter;
	      best_bob = val;
	      first_bob = false;
	    }
	    else if (val < best_bob) {
	      best_bob_id = bob_counter;
	      best_bob = val;
	    }
	  }
	selected[best_bob_id] = true;
	current_gain += grid[alice[alice_counter]][best_bob_id];
	if (first) {
	  best_gain = current_gain;
	  first = false;
	}
	else if (current_gain > best_gain)
	  best_gain = current_gain;
      }
      } while (next_permutation(alice.begin(), alice.end()));
      cout << best_gain << endl;
    }
    return 0;
  }
