#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main (void){
  unsigned int n, l, u, o;
  while (cin >> n >> l >> u) {
    o = 0;
    bool c_l = true, c_u = true;
    for (int i=31; i>=0; i--) {
      int lb = l & (1<<i);
      int ub = u & (1<<i);
      int nb = n & (1<<i);
      bool szero = false, sone = false;
      if (c_u && !ub)
	continue;
      else if (c_l && lb) {
	o |= (1<<i);
	if (!lb)
	  c_l = false;
	continue;
      }
      else {
	if (nb && ub)
	    c_u = false;
	if (!nb) {
	  o |= (1<<i);
	  if (!lb)
	    c_l = false;
	}
      }
    }
    cout << o << endl;
  }
  return 0;
}

