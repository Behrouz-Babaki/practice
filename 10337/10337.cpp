#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::min;

int main(void) {
  int num_cases;
  cin >> num_cases;
  for (int case_cnt = 0; case_cnt < num_cases; case_cnt++) {
    int miles;
    cin >> miles;
    miles /= 100;
    vector<vector<int> > wind(10, vector<int>(miles));
    vector<vector<int> > cost(10, vector<int>(miles));

    for (int alt=9; alt>=0; alt--) 
      for (int segment = 0; segment < miles; segment++)
	cin >> wind[alt][segment];

    cost[0][0] = 30 - wind[0][0];
    cost[1][0] = 60 - wind[0][0];
    for (int alt=2; alt<=9; alt++)
      cost[alt][0] = 10000;


    for (int segment = 1; segment < miles; segment++) 
      for (int alt = 0; alt < 10; alt++) {
	cost[alt][segment] = cost[alt][segment-1] + 30 - wind[alt][segment];
	if (alt > 0)
	  cost[alt][segment] = min(cost[alt][segment], 
				   cost[alt-1][segment-1] + 60 - wind[alt-1][segment]);
	if (alt < 9)
	  cost[alt][segment] = min(cost[alt][segment], 
				   cost[alt+1][segment-1] +20 - wind[alt+1][segment]);
      }
    
    cout << cost[0].back() << endl << endl;
    
  }
  return 0;
}
