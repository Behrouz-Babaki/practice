#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main() {
  int n, k;
  cin >> n >> k;
  while (n && k) {
    vector<vector<int> > ways(n+1, vector<int>(k+1, 1));
    for (int j=0; j<k+1; j++)
      ways[0][j] = 0;

    for (int i=1; i<=n; i++) {
      ways[i][0] = 0;
      for (int j=1; j<=k; j++)
	for (int w = 0; w <=i; w++)
	  ways[i][j] = (ways[i][j] + ways[i-w][j-1]) % 1000000;
    }
    
    cout << ways[n][k] << endl;
    cin >> n >> k;
  }
  return 0;
}
