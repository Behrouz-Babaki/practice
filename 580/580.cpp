#include <iostream>
#include <vector>
#include <cmath>

using std::cin;
using std::endl;
using std::cout;
using std::vector;
using std::pow;

int main(void) {
  int n;
  cin >> n;

  while (n > 0) {

    vector<vector<int> > ways (2, vector<int> (n));
    ways [0][0] = ways [1][0] = 1;

    if (n > 1) {
      ways [0][1] = 2;
      ways [1][1] = 2;
    
      for (int counter = 2; counter < n; counter++) {
	ways [0][counter] = ways [0][counter-1] + ways [1][counter-1];
	ways [1][counter] = ways [0][counter-1] + ways [0][counter-2];
      }
    }

    long stableWays = ways[0][n-1] + ways[1][n-1];
    cout << pow(2,n) - stableWays << endl;

    cin >> n;
  }

  return 0;
}
