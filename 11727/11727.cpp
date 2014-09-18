#include <iostream>
using std::cin;
using std::endl;
using std::cout;

int main(void) {
  size_t num_cases;
  cin >> num_cases;
  for (size_t case_counter = 0; case_counter < num_cases; case_counter++) {
    size_t salary[3];
    cin >> salary[0] >> salary[1] >> salary[2];
    size_t max = 0, mid = 0;
    for (int staff_counter = 0; staff_counter < 3; staff_counter++) 
      if (salary[staff_counter] > max) {
	mid = max;
	max = salary[staff_counter];
    }
      else if (salary[staff_counter] > mid)
	mid = salary[staff_counter];

    cout << "Case " << case_counter + 1 << ": " << mid << endl;
  }
  return 0;
}
