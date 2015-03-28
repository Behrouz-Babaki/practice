#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::vector;

int main(void) {
  int num_cases;
  cin >> num_cases;
  while (num_cases--) {
    int shortcuts[101];
    for (int i = 0; i <= 100; i++)
      shortcuts[i] = -1;
    int num_players, num_shortcust, num_rolls;
    cin >> num_players >> num_shortcust >> num_rolls;
    vector<int> positions(num_players,1);
    while (num_shortcust--) {
      int head, tail;
      cin >> head >> tail;
      shortcuts[head] = tail;
    }
    bool win = false;
    int current_player = 0;
    while (num_rolls--) {
      int roll;
      cin >> roll;
      if (!win) {
	int new_pos = positions[current_player] + roll;
	if (new_pos >= 100)
	  positions[current_player] = 100;
	else {
	  positions[current_player] = new_pos;
	  if (shortcuts[new_pos] != -1)
	    positions[current_player] = shortcuts[new_pos];
	}
	if (positions[current_player] == 100)
	  win = true;
	current_player = (current_player + 1) % num_players;
      }
    }
    for (int j = 0; j < num_players; j++)
      cout << "Position of player " << j+1 << " is " << positions[j] << "." << endl;
  }
  return 0;
}
