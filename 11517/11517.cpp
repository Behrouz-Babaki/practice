#include <iostream>
#include <vector>
#include <utility>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::pair;
using std::make_pair;
using std::min;

int main(void) {
  int num_cases;
  cin >> num_cases;
  for (int case_cnt = 0; case_cnt < num_cases; case_cnt++) {
    int price, num_coins; 
    cin >> price >> num_coins;
    vector<int> coins(num_coins+1);
    for (int coin_cnt = 1; coin_cnt <= num_coins; coin_cnt++)
      cin >> coins[coin_cnt];

    vector<vector<pair<int, int> > > num(price + 1, vector<pair<int, int> > (num_coins+1));

    for (int j = 0; j <= num_coins; j++)
      num[0][j] = make_pair(0, 0);

    for (int i = 1; i <= price; i++)
      num[i][0] = make_pair(100000, 100000);

    for (int i = 1; i <= price ; i++)
      for (int j = 1; j <= num_coins; j++) {
	pair<int, int> choice1, choice2, next, test;
	if (i < coins[j]) {
	  choice1 = make_pair(coins[j], 1);
	  choice2 = num[i][j-1];
	  num[i][j] = min(choice1, choice2);
	}
	else {

	  choice1 = num[i][j-1];
	  next = num[i-coins[j]][j-1];
	  choice2 = make_pair(coins[j]+next.first, 1+next.second);
	  num[i][j] = min(choice1, choice2);
	}
      }

    pair<int, int> res = num[price][num_coins];
    cout << res.first << " " << res.second << endl;
  }

  return 0;
}
