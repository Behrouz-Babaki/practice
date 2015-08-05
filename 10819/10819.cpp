#include <iostream>
#include <string.h>

using std::cin;
using std::cout;
using std::endl;
using std::max;

int memo[10001][101];
int memo_neg[201][101];
int prices[101], favors[101];
int total_money, num_items;
int inf = 1000;

int get_memo(int, int);
int get_memo_neg(int, int);

int main(void) {
  while(cin >> total_money >> num_items) {
    for (int item_cnt = 1; item_cnt <= num_items; item_cnt++)
      cin >> prices[item_cnt] >> favors[item_cnt];
    memset(memo, -1, sizeof memo);
    memset(memo_neg, -1, sizeof memo_neg);
    cout << get_memo(total_money, 1) << endl;
   }
  return 0;
}

int get_memo(int budget, int id) {
  if (budget < 0)
    return get_memo_neg(budget, id);
  if (id > num_items)
    return 0;
  if (memo[budget][id] >= 0)
    return memo[budget][id];
  memo[budget][id] = max(get_memo(budget, id+1), 
			 favors[id] + get_memo(budget-prices[id], id+1));
  return memo[budget][id];
}

int get_memo_neg(int budget, int id) {
  if (budget < -200)
    return -inf;
  if (id > num_items) {
    if (-budget+total_money > 2000)
      return 0;
    else 
      return -inf;
  }
  if (memo_neg[-budget][id] >=0)
    return memo_neg[-budget][id];
  memo_neg[-budget][id] = max(get_memo_neg(budget, id+1), 
			      favors[id] + get_memo_neg(budget-prices[id], id+1));
  return memo_neg[-budget][id];
}
