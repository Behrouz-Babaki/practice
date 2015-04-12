#include <iostream>
#include <iomanip>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::ws;
using std::setw;
using std::right;
using std::left;
using std::string;

int rows, columns;
void b2d(string& line);
void d2b(string& line);

int main(void) {
  char format;
  cin >> format;
  while (format!='#') {
    cin >> rows >> columns >> ws;
    string line;
    getline(cin, line);
    if (format=='B')
      b2d(line);
    else
      d2b(line);
    cin >> format;
  }
  return 0;
}

void b2d(string& line) {
}

void d2b(string& line){
}

/*
  cout << 'D' << setw(4) << right << 3 << setw(4) << 4 << endl;
  cout << setw(50) << left << "D0D1001D101" << endl;
*/
