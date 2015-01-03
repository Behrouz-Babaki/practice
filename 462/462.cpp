#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <utility>

using std::endl;
using std::cout;
using std::cin;
using std::string;
using std::istringstream;
using std::vector;
using std::map;
using std::make_pair;

int main (void) {
  char suits[] = {'S', 'H', 'D', 'C'};

  string line;
  while(getline(cin,line)){
    istringstream ss(line);
    vector<string> cards;
    for(int card_counter = 0; card_counter < 13; card_counter++) {
      string card;
      ss >> card;
      cards.push_back(card);
    }

    size_t score = 0;
    vector<bool> stopped (4, false);
    vector<size_t> card_counts (4,0);
    /* count cards in each suit */
    for (int counter = 0; counter < 13; counter++){
      bool found = false;
      for (int suit_counter = 0; !found && suit_counter < 4; suit_counter++)
	if (cards[counter][1] == suits[suit_counter]){
	  card_counts[suit_counter]++;
	  found = true;
	}
    }
    
    /* why another pass just for finding max? */
    size_t max_count = 0;
    size_t max_id = 0;
    for (size_t suit_counter = 0; suit_counter < 4; suit_counter++) 
      if (card_counts[suit_counter] > max_count){
	max_count = card_counts[suit_counter];
	max_id = suit_counter;
      }

    /* compute the score */
    for (int counter = 0; counter < 13; counter++) {
      int suit;
      bool found = false;
      for (int suit_counter = 0; !found && suit_counter < 4; suit_counter++)
	if (cards[counter][1] == suits[suit_counter]){
	  suit = suit_counter;
	  found = true;
	}
      if (cards[counter][0] == 'A'){
	score  += 4;
	stopped[suit] = true;
	continue;
      }
      if (cards[counter][0] == 'K'){
	score += 3;
	if (card_counts[suit] == 1)
	  score --;
	else
	  stopped[suit] = true;

	continue;
      }
      if (cards[counter][0] == 'Q'){
	score += 2;
	if (card_counts[suit] < 3)
	  score --;
	else 
	  stopped[suit] = true;
	continue;
      }
      if (cards[counter][0] == 'J'){
	score += 1;
	if (card_counts[suit] < 4)
	  score --;
	continue;
      }
    }

    bool bid = false;
    
    bool all_stopped = true;
    for (size_t suit_counter = 0; all_stopped && suit_counter < 4; suit_counter++)
      if (!stopped[suit_counter])
	all_stopped = false;

    if (all_stopped && score >= 16) {
      cout << "BID NO-TRUMP" << endl;
      bid = true;
    }

    if (!bid){
      for (size_t suit_counter = 0; suit_counter < 4; suit_counter++)
	switch(card_counts[suit_counter]){
	case 2:
	  score += 1;
	  break;
	case 1:
	case 0:
	  score += 2;
	  break;
	}

      if (score >= 14){
	cout << "BID " << suits[max_id] << endl;
	bid = true;
      }
	
    }

    if (!bid)
      cout << "PASS" << endl;

  } //getline
  return 0;
}

