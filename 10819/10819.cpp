#include <iostream>
#include <string.h>

using std::cin;
using std::cout;
using std::endl;

int memo[100001][101];

int main(void) {
  int total_money, num_items;
  while(cin >> total_money >> num_items) {
    int prices[num_items], favors[num_items];
    for (int item_cnt = 0; item_cnt < num_items; item_cnt++)
      cin >> prices[item_cnt] >> favors[item_cnt];
    memset(memo, -1, sizeof memo);
    
    // compute here ...
    
  }
  return 0;
}

