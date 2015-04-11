#include <iostream>
#include <cmath>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::fixed;

double f(double x);

int p, q, r, s, t, u;
int main(void) {

  while (cin >> p >> q >> r >> s >> t >> u) {
    double lo, mid, hi;
    lo = 0;
    hi = 1;
    double flo, fmid, fhi;
    flo = f(lo);
    fhi=f(hi);
    bool fail=false;
    while (!fail && fabs(hi-lo) > 1e-7) {
      mid=(lo+hi)/2.0;
      fmid=f(mid);
      if (fmid*fhi > 0) {
	if (fmid*flo > 0) 
	  fail = true; 

	hi=mid;
	fhi=fmid;
      }
      else {
	lo=mid;
	flo=fmid;
      }
    }
    if (fail || fhi*flo>0)
      cout << "No solution" << endl;
    else
      printf("%.4f\n", hi);
  }
  return 0;
}

double f(double x) {
  double result = p * exp(-x);
  result += q * sin(x);
  result += r * cos(x);
  result += s * tan(x);
  result += t*x*x;
  result += u;
  return result;
}
