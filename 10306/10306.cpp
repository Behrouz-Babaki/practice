#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::pair;
using std::make_pair;
using std::sqrt;
using std::pow;
using std::min;
using std::map;

class Triplet {
public: 
  Triplet (int a, int b, int c) {
    this-> a = a;
    this-> b = b;
    this-> c = c;
  }
  bool operator<(const Triplet& rhs) const{
    if (this->a != rhs.a)
      return this->a < rhs.a;
    if (this-> b != rhs.b)
      return this->b < rhs.b;
    return (this->c < rhs.c);
  }
  int a, b, c;
};

map<Triplet , int> coins;
vector<pair<int, int> > type_info;

int get_coins(int coin_type, 
	      int v_conv, 
	      int v_it);

int main(void) {
  int num_cases;
  cin >> num_cases;
  for (int case_cnt = 0; case_cnt <num_cases; case_cnt++) {
    int n_types, sum;
    cin >> n_types >> sum;

    vector<pair<int, int> > components;
    for (int cnt = 0; cnt <=sum; cnt++) {
      int res2 = pow(sum, 2) - pow(cnt, 2);
      int sq = sqrt(res2);
      if (sq*sq == res2)
	components.push_back(make_pair(cnt, sq));
    }

    type_info.clear();
    type_info.resize(n_types);
    for (int type_cnt =0; type_cnt < n_types; type_cnt++) {
      int conv, it;
      cin >> conv >> it;
      type_info[type_cnt] = make_pair(conv, it);
    }

    int min_coins; 
    bool first = true;
    for (auto component : components) {
      coins.clear();
      if (first) {
	min_coins = get_coins(0, component.first, component.second);
	first = false;
      }
      else 
	min_coins = min(min_coins, get_coins(0, component.first, component.second));
    }
    
    if (min_coins < 100000)
      cout << min_coins << endl;
    else
      cout << "not possible" << endl;
  }
  return 0;
}

int get_coins(int coin_type, 
	      int v_conv, 
	      int v_it) {
  if (v_conv == 0 && v_it == 0)
    return 0;

  if (coin_type == type_info.size()) 
    return 100000;

  Triplet tr = Triplet(coin_type, v_conv, v_it);
  if (coins.find(tr) != coins.end())
    return (coins[tr]);
    
  int first = type_info[coin_type].first, 
    second = type_info[coin_type].second;
  if (v_conv < first||
      v_it < second)
    return get_coins(coin_type+1, v_conv, v_it);
  
  int counts = 0;
  int min_counts; 

  while (counts * first <= v_conv &&
	 counts * second <= v_it) {
      int current_counts = counts + get_coins(coin_type+1, 
			     v_conv - counts * first, 
			     v_it - counts * second);
    if (counts == 0)
      min_counts = current_counts;
    else 
      min_counts = min(min_counts, current_counts);
    counts++;
  }

  coins[tr] = min_counts;
  return min_counts;
}
