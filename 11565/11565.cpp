#include <iostream>
#include <cmath>

using std::cout;
using std::endl;
using std::cin;
using std::sqrt;
using std::min;

int main(void) {
  int num_cases;
  cin >> num_cases;
  while (num_cases--) {
    int A, B, C;
    cin >> A >> B >> C;
    bool found = false;
    bool cond1 = false,
      cond2 = false;
    int low;
    if (!B)
      low = sqrt(C);
    else
      low = min(int(sqrt(C)), B);
    for (long x = -low; !found && !cond1; x++) {
      if (x*x > C)
	cond1 = true;
      else 
	cond2 = false;
	for (long y = x+1; !found && !cond1 && !cond2; y++) {
	  long z = A - x - y;
	  if (z <= y)
	    cond2 = true;
	  if (x*x + y*y > C)
	    cond2 = true;
	  if (!cond2 && x*y*z == B &&
	      (x*x + y*y + z*z == C)) {
	    found = true;
	    cout << x << " " << y << " " << z << endl;
	  }
	}
    }
    if (!found)
      cout << "No solution." << endl;
  }
  return 0;
}
