#include <iostream>
#include <iomanip>
#include <vector>

using std::cin;
using std::endl;
using std::cout;
using std::right;
using std::setw;
using std::vector;

int main(void) {
  vector<unsigned long int> last6Digs (10001);
  last6Digs[0] = 1;
  for (int counter = 1; counter <= 10000; counter++)
    {
      long unsigned int nextnum = counter * last6Digs[counter-1];
      while (nextnum%10 == 0)
	nextnum /= 10;

      if (nextnum >= 10000000)
	nextnum %= 10000000;

      last6Digs[counter] = nextnum;
    }

  int input;
  while (cin >> input)
    cout << setw(5) << right << input << " -> " << last6Digs[input]%10 << endl;

  return 0;
}
