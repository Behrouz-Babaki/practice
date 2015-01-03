#include <iostream>
#include <string>
#include <vector>

using std::endl;
using std::cout;
using std::cin;
using std::ws;
using std::string;
using std::vector;

int main (void) {
  char suits[] = {'S', 'H', 'D', 'C'};

  size_t num_cases;
  cin >> num_cases >> ws;
  for (size_t case_counter = 0; case_counter < num_cases; case_counter++) {
    vector<string> cards (52);
    vector<bool> in_pile (52,true);
    vector<size_t> scores (52);
    for(int card_counter = 51; card_counter >= 0; card_counter--) {
      string card;
      cin >> card >> ws;
      cards[card_counter] = card;

      if (card[0] >= 50 && card[0] <= 57)
	scores[card_counter] = card[0] - 48;
      else 
	scores[card_counter] = 10;
    }

    size_t position = 25;
    size_t y = 0;
    for (size_t counter = 0; counter < 3; counter++){
      size_t score = scores[position];
      y += score;
      for (size_t out_counter = 0; out_counter <= 10 - score; out_counter++){
	in_pile[position] = false;
	position++;
      }
    }

    position = 51;
    size_t card_count = 1;
    while (card_count < y) {
      if (in_pile[position])
	card_count++;
      position --;
    }

    cout << "Case " << case_counter + 1 << ": "  << cards[position] << endl;

  }

  return 0;
}
