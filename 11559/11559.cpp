#include <iostream>

using std::endl;
using std::cin;
using std::cout;

int main(void) {
  size_t num_participants, budget, num_hotels, num_weeks;
  cin >> num_participants >> budget >> num_hotels >> num_weeks;

  while (cin.good()) {
    int best_price = -1;
    for (size_t hotel_counter = 0; hotel_counter < num_hotels; hotel_counter++) {
      size_t price;
      cin >> price;

      bool has_capacity = false;
      size_t beds;
      for (size_t week_counter = 0; week_counter < num_weeks; week_counter++){
	cin >> beds;
	if (beds >= num_participants)
	  has_capacity = true;
      }
	
      if (has_capacity && (best_price < 0 || price < best_price)) 
	best_price = price;
    }
    
    if (best_price < 0 || best_price * num_participants > budget)
      cout << "stay home" << endl;
    else 
      cout << best_price * num_participants << endl;
      
    cin >> num_participants >> budget >> num_hotels >> num_weeks;
  }
  return 0;
}
