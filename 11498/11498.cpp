#include <iostream>

using std::endl;
using std::cout;
using std::cin;


int main(void) {
  int num_cases;
  cin >> num_cases;
  while (num_cases > 0) {
    int div_x, div_y;
    cin >> div_x >> div_y;
    for (int point_counter = 0; point_counter < num_cases; point_counter++) {
      int point_x, point_y;
      cin >>  point_x >> point_y;
      if (point_x > div_x) {
	if (point_y > div_y)
	  cout << "NE" << endl;
	else if (point_y < div_y)
	  cout << "SE" << endl;
	else
	  cout << "divisa" << endl;
      }
      else if (point_x < div_x) {
	if (point_y > div_y)
	  cout << "NO" << endl;
	else if (point_y < div_y)
	  cout << "SO" << endl;
	else
	  cout << "divisa" << endl;
      }
      else
	cout << "divisa" << endl;
    }
    cin >> num_cases;
  }
  return 0;
}
