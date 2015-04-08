
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

    vector<int> bob(size);
    for (int i = 0; i < size; i++) 
      bob[i] = i;

    int best_gain;
    bool first = true;
    do{
      int current_gain = 0;
      for (int i = 0; i < size; i++)
	current_gain += grid[i][bob[i]];
      if (first) {
	best_gain = current_gain;
	first = false;
      }
      if (best_gain > current_gain)
	best_gain = current_gain;

    } while (next_permutation(bob.begin(), bob.end()));

      cout << best_gain << endl;
    }
    return 0;
  }
