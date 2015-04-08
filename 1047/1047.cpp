#include <iostream>
#include <set>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::set;
using std::vector;

int main(void) {
  int planned, built;
  cin >> planned >> built;
  int case_counter = 1;

  while (planned || built) {
    vector<int> customers(planned);
    for (int i = 0; i < planned; i++)
      cin >> customers[i];
    int num_common;
    cin >> num_common;
    vector<int> populations(num_common);
    vector<set<int> > commons(num_common);
    for (int i = 0; i < num_common; i++) {
      int num_towers;
      cin >> num_towers;
      set<int> towers;
      int current_tower;
      for (int j = 0; j < num_towers; j++) {
	cin >> current_tower;
	towers.insert(current_tower-1);
      }
      commons[i] = towers;
      cin >> populations[i];
    }

    int best_num = 0;
    vector<int> best_locations;
    int M = (1<<planned);
    while (--M) { 
      int ones = 0;
      int total = 0;
      for (int i = 0; i < planned; i++)
    	if (M & (1<<i)) {
    	  total += customers[planned-i-1];
    	  ones++;
    	}
      if (ones != built)
    	continue;
      for (int j = 0; j < num_common; j++) {
    	int common_towers = 0;
    	for (int i = 0; i < planned; i++)
    	  if (M & (1<<i) && commons[j].find(planned-i-1) != commons[j].end()) 
    	    common_towers++;
	if (common_towers > 1)
	  total -= (common_towers-1)*populations[j];
      }
      if (total > best_num) {
    	best_num = total;
    	best_locations.clear();
    	for (int i = planned-1; i >= 0; i--)
    	  if (M&(1<<i))
    	    best_locations.push_back(planned-i);
      }
    }
    cout << "Case Number  " << case_counter++ << endl;
    cout << "Number of Customers: " << best_num << endl;
    cout << "Locations recommended: ";
    for (int i = 0, size = best_locations.size(); i < size; i++) {
      cout << best_locations[i];
      if (i < size-1)
	cout << " ";
    }
    cout << endl << endl;
    cin >> planned >> built;
  }  
  return 0;
}
