#include <iostream>
#include <vector>
#include <utility>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::pair;
using std::make_pair;
using std::map;
using std::max;

map<pair<int, int>, pair<int, int> > memo;
vector<int> prices, favors;
int total_money, num_items;
pair<int, int> get_favor(int id, int budget);

int main(void) {
  while(cin >> total_money >> num_items) {
    prices.resize(num_items);
    favors.resize(num_items);
    for (int item_cnt = 0; item_cnt < num_items; item_cnt++)
      cin >> prices[item_cnt] >> favors[item_cnt];
    pair<int, int> f1, f2;
    f2 = get_favor(0, total_money + 200);
    int result;
    if (f2.second > 2000)
      result = f2.first;
    else {
      f1 = get_favor(0, total_money);
      memo.clear();
      result = f1.first;
    }
    cout << result << endl;
  }
  return 0;
}

pair<int, int> get_favor(int id, int budget) {
  if (id == num_items || budget <= 0)
    return make_pair(0, 0);
  pair<int, int> id_b = make_pair(id, budget);
  if (memo.find(id_b) != memo.end())
    return memo[id_b];
  pair<int,int> favor;
  if (prices[id] > budget) 
    favor = get_favor(id+1, budget);
  else {
    pair<int, int> f1 = get_favor(id+1, budget);
    pair<int, int> f2 = get_favor(id+1, budget - prices[id]);
    if (f1.first > f2.first + favors[id]) 
      favor = f1;
    else {
      favor.first = f2.first + favors[id];
      favor.second = f2.second + prices[id];
    }
  }
  memo[id_b] = favor;
  return favor;
}
