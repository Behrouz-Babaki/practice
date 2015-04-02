#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main(void) {
  int sz, p;
  cin >> sz >> p;
  while (sz && p) {
    int n = 1, x = sz/2+1, y = sz/2+1;
    int ul, dr;
    ul = 1;
    while (n < p) {
      for  (int i = 0; n < p && i < ul; i++) {
	y ++;
	n ++;
      }
      for  (int i = 0; n < p && i < ul; i++) {
	x --;
	n ++;
      }
      dr = ul + 1;
      for  (int i = 0; n < p && i < dr; i++) {
	y --;
	n ++;
      }
      for  (int i = 0; n < p && i < dr; i++) {
	x ++;
	n ++;
      }
      ul = dr + 1;
    }
    cout << "Line = " << y << "," << " column = " << x << "." << endl;
    cin >> sz >> p;
  }
  return 0;
}
