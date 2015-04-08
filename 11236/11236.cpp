#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::setprecision;
using std::fixed;

int main(void) {
  for (long first = 0; first <= 2000; first ++)  {
    for (long second = first ; second <= 2000 - first; second ++) {
      for (long third = second ; third <= (2000 - first - second) ; third ++) {
	double sum = first+second+third+0.0;
	double mult = first*second*third*1.0;
	double fourth = (1000000*sum)/(mult-1000000);
	  if (fourth >= third && sum+fourth <= 2000)
	    cout << setprecision(2) << fixed << 
	      first << " " << 
	      second << " " << 
	      third << " " << 
	      fourth << endl;
	
      }
    }
  }
  return 0;
}
