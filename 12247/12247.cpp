#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using std::cin;
using std::endl;
using std::cout;
using std::vector;
using std::set;
using std::sort;

int play(vector<int>& princess, vector<int>& prince);

int main(void) {
  int card;
  cin >> card;
  while (card > 0) {
    vector<int> princess, prince;
    set<int> cards;
    princess.push_back(card);
    cards.insert(card);
    for (int card_cnt = 0; card_cnt < 2; card_cnt++) {
      cin >> card;
      princess.push_back(card);
      cards.insert(card);
    }
	
    for (int card_cnt = 0; card_cnt < 2; card_cnt++) {
      cin >> card;
      prince.push_back(card);
      cards.insert(card);
    }

    sort (prince.begin(), prince.end());
    sort (princess.begin(), princess.end());

    int wins = 0; 
    while (!prince.empty())
      wins += play(princess, prince);

    if (wins == 0)
      cout << "-1" << endl;
    else {
      int next_card;
      if (wins == 1)
	next_card = princess[0] + 1;
      else 
	next_card = 1;
      int last_card = -1;
      for (; last_card < 0 && next_card <= 52; next_card++)
	if (cards.find(next_card) == cards.end())
	  last_card = next_card;
      cout << last_card << endl;
    }
    cin >> card;
  }
  return 0;
}


int play(vector<int>& princess, vector<int>& prince) {
  /* princess: play the lowest bigger than lowest of prince
   * If no such thing exists, play the lowest card.
   */
  int princess_card = -1;
  vector<int>::iterator princess_itr;
  for (vector<int>::iterator itr = princess.begin(), end_itr = princess.end(); princess_card < 0 && itr != end_itr; itr++)
    if (*itr > prince.front()){
      princess_card = *itr;
      princess_itr = itr;
    }
  
  if (princess_card > 0) {
    princess.erase(princess_itr);
    bool found = false;
    for (size_t prince_card_cnt = prince.size() -1 ; !found && prince_card_cnt >= 0; prince_card_cnt --) 
      if (prince[prince_card_cnt] < princess_card){
	found = true;
	prince.erase(prince.begin() + prince_card_cnt);
      }
      return 0;
  }
    
  else {
    princess.erase(princess.begin());
    prince.erase(prince.end() - 1);
    return 1;
  }
}
