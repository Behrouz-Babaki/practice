#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::setprecision;
using std::fixed;

int main(void) {
  for (double first = 0.49; first <= 20; first += 0.01)  {
    cout << first << endl;
    for (double second = first ; second <= (20 - first); second += 0.01) {
      for (double third = second ; third <= (20 - first - second) ; third += 0.01) {
	for (double fourth = third ; fourth <= (20 - first - second - third) ;fourth += 0.01) {
	  if ((first+second+third+fourth) == (first*second*third*fourth))
	    cout << setprecision(2) << fixed << 
	      first << " " << 
	      second << " " << 
	      third << " " << 
	      fourth << endl;
	}
      }
    }
  }
  return 0;
}
