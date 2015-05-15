#include <iostream>
#include <stack>
#include <vector>

using std::endl;
using std::cout;
using std::cin;
using std::vector;
using std::stack;

int main(void) {
  int num_cases;
  cin >> num_cases;
  while (num_cases--){
    int num_types;
    cin >> num_types;

    vector<int> coins(num_types);
    for(int coin_cnt=0; coin_cnt<num_types; coin_cnt++)
      cin >> coins[coin_cnt];

    long int sum = 0;
    int id = 0, num=0;
    while (id < coins.size()){
      if (id+1 == coins.size() ||
	  sum + coins[id] < coins[id+1]) {
	num++;
	sum += coins[id];
      }
      id++;
    }
    cout << num << endl;
  }
  return 0;
}
