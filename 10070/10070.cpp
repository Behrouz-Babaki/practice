#include <iostream>
using std::cout;
using std::endl;
using std::cin;

/* Solving this requires using big numbers */

int main(void){
  unsigned long int year;
  while (cin >> year){
    bool leap = false, huluculu = false, bulukulu = false;
    if (year % 4 == 0 && year % 100 != 0)
      leap = true;
    if (year % 400 == 0)
      leap = true;
    if (year % 15 == 0)
      huluculu = true;
    if (leap && year % 55 == 0)
      bulukulu = true;
    
    if (leap)
      cout << "This is leap year." << endl;
    if (huluculu)
      cout << "This is huluculu festival year." << endl;
    if (bulukulu)
      cout << "This is bulukulu festival year." << endl;
    
    if (!leap && !huluculu && !bulukulu)
      cout << "This is an ordinary year." << endl;

    cout << endl;
  }
  return 0;
}
