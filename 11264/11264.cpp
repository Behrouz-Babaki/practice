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
    int num = 0;
    for (int coin_cnt=0; coin_cnt<num_types; coin_cnt++)
      if (coins[coin_cnt] > sum){
	num++;
	sum += coins[coin_cnt];
      }
    cout << num << endl;
  }
  return 0;
}
