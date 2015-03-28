#include <iostream>

using std::cout;
using std::endl;
using std::cin;

bool is_leap(int);
int n_days[2][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
		     {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int main(void) {
  int n, day, month, year;
  cin >> n >> day >> month >> year;
  while (n || day || month || year) {
    int leap = is_leap(year);
    int current_month = month;
    if ((n+day) <= n_days[leap][month-1]) {
      cout << day+n << " " << month << " " << year << endl;
      cin >> n >> day >> month >> year;
      continue;
    }
    else {
      n -= (n_days[leap][month-1] - day);
      current_month++;
    }
    while (current_month <= 12 && n > n_days[leap][current_month-1]) {
      n -= (n_days[leap][current_month-1]);
      current_month ++;
    }
    if (current_month <= 12 && n <= n_days[leap][current_month-1]) {
      cout << n << " " << current_month << " " << year << endl;
      cin >> n >> day >> month >> year;
      continue;
    }
    year++;
    int year_days;
    year_days = is_leap(year) ? 366 : 365;
    while (n > year_days) {
      n -= year_days;
      year++;
      year_days = is_leap(year) ? 366 : 365;
    }
    current_month = 1;
    leap = is_leap(year);
    while (n > n_days[leap][current_month-1]) {
      n -= (n_days[leap][current_month-1]);
      current_month++;
    }
    cout << n << " " << current_month << " " << year << endl;
    cin >> n >> day >> month >> year;
  }
  return 0;
}

bool is_leap(int year) {
  if (year%4 != 0)
    return false;

  if (year%100 != 0 || year%400 == 0)
    return true;
  return false;
}
