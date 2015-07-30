#include <iostream>
#include <vector>

using std::cin;
using std::endl;
using std::cout;
using std::vector;

int main(void) {
  int n, k, m;
  while (cin >> n >> k >> m) {
    vector<vector<long int> > bc(n+1, vector<long int>(k+1, 0));
    bc[0][0] = 1;
    bc[1][1] = 1;

    for (int i=2; i<=n; i++) 
      for (int j=1; j<=k; j++)
	for (int w=1; w<=m && w<=i; w++)
	  bc[i][j] += bc[i-w][j-1];

    // for (auto row: bc) {
    //   for (auto col: row)
    // 	cout << col << "\t";
    // cout << endl;
    // }

    cout << bc[n][k] << endl;
  }
  return 0;
}
