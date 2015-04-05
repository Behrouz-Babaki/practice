
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
    vector<int> bob(size);
    for (int i = 0; i < size; i++) {
      alice[i] = i;
      bob[i] = i;
    }

    int best_gain;
    bool first_alice = true;
    do {
      bool first_bob = true;
      int best_bob;
      do {
	int current_gain = 0;
	for (int i = 0; i < size; i++) 
	  current_gain += grid[alice[i]][bob[i]];
	  if (first_bob) {
	    first_bob = false;
	    best_bob = current_gain;
	  }
	  else if (current_gain < best_bob) 
	    best_bob = current_gain;
      } while (next_permutation(bob.begin(), bob.end()));
      if (first_alice) {
	first_alice = false;
	best_gain = best_bob;
      }
      else if (best_bob > best_gain)
	best_gain = best_bob;
      } while (next_permutation(alice.begin(), alice.end()));
      cout << best_gain << endl;
    }
    return 0;
  }
