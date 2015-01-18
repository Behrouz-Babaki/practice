#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::multiset;
using std::min;
using std::vector;

int main(void) {
  size_t num_cases;
  cin >> num_cases;
  for (size_t case_cnt = 0; case_cnt < num_cases; case_cnt++) {
    size_t num_fields, num_green, num_blue;
    cin >> num_fields >> num_green >> num_blue;

    size_t current_soldier;
    multiset<size_t> green_power;
    for (size_t green_cnt = 0; green_cnt < num_green; green_cnt++) {
      cin >> current_soldier;
      green_power.insert(current_soldier);
    }

    multiset<size_t> blue_power;
    for (size_t blue_cnt = 0; blue_cnt < num_blue; blue_cnt++) {
      cin >> current_soldier;
      blue_power.insert(current_soldier);
    }

    while (!green_power.empty() && !blue_power.empty()) {
      vector<size_t> blue_back, green_back;
      size_t nfields;
      nfields = min(num_fields, green_power.size());
      nfields = min(nfields, blue_power.size());
      for (size_t battle_cnt = 0; battle_cnt < nfields; battle_cnt++) {
	auto  blue = blue_power.end(),
	  green = green_power.end();
	if (*(--blue) > *(--green))
	  blue_back.push_back(*blue - *green);
	else if (*blue < *green)
	  green_back.push_back(*green - *blue);

	green_power.erase(green);
	blue_power.erase(blue);
      }
      blue_power.insert(blue_back.begin(),
			blue_back.end());
      green_power.insert(green_back.begin(),
			 green_back.end());
    }
    
    if (green_power.empty() && blue_power.empty())
      cout << "green and blue died" << endl;
    else if (green_power.empty()) {
      cout << "blue wins" << endl;
      for (auto itr= blue_power.rbegin(), end = blue_power.rend();
	   itr != end; itr++)
	cout << *itr << endl;
    }
    else {
      cout << "green wins" << endl;
      for (auto itr= green_power.rbegin(), end = green_power.rend();
	   itr != end; itr++)
	cout << *itr << endl;

    }
    if (case_cnt < num_cases - 1)
      cout << endl;
  }
  return 0;
}
