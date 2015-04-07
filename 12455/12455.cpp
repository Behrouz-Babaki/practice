#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main(void) {
  int num_cases;
  cin >> num_cases;
  while (num_cases--) {
    int target; 
    cin >> target;
    int num_bars;
    cin >> num_bars;
    vector<int> lengths(num_bars);
    for (int i = 0; i < num_bars; i++)
      cin >> lengths[i];
    bool found = false;
    int M = 0;
    while (!found && !(M & (1<<num_bars))) {
      int sum = 0;
      for (int i = 0; i < num_bars; i++)
	if (M & (1<<i))
	  sum += lengths[i];
      if (sum == target)
	found = true;
      M++;
    }
    if (found)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
