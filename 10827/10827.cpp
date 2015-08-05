#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::max;

int main(void) {
  int num_cases;
  cin >> num_cases;
  for (int case_cnt=0; case_cnt < num_cases; case_cnt++) {
    int n ;
    cin >> n;
    vector<vector<int> > torus(n, vector<int> (n));
    vector<vector<int> > ul(n, vector<int> (n));
    vector<vector<int> > lr(n, vector<int> (n));

    for (int row_cnt =0; row_cnt < n; row_cnt++)
      for (int col_cnt = 0; col_cnt < n; col_cnt++) 
	cin >> torus[row_cnt][col_cnt];

    for (int row_cnt =0; row_cnt < n; row_cnt++)
      for (int col_cnt = 0; col_cnt < n; col_cnt++) {
	ul[row_cnt][col_cnt] = torus[row_cnt][col_cnt];
    	if (row_cnt > 0)
	  ul[row_cnt][col_cnt] += ul[row_cnt-1][col_cnt];
	if (col_cnt > 0)
	  ul[row_cnt][col_cnt] += ul[row_cnt][col_cnt-1];
	if (row_cnt > 0 && col_cnt > 0)
	  ul[row_cnt][col_cnt] -= ul[row_cnt-1][col_cnt-1];
      }

    for (int row_cnt = n-1; row_cnt >= 0; row_cnt--)
      for (int col_cnt = n-1; col_cnt >= 0; col_cnt--) {
	lr[row_cnt][col_cnt] = torus[row_cnt][col_cnt];
    	if (row_cnt < n-1)
	  lr[row_cnt][col_cnt] += lr[row_cnt+1][col_cnt];
	if (col_cnt < n-1)
	  lr[row_cnt][col_cnt] += lr[row_cnt][col_cnt+1];
	if (row_cnt < n-1 && col_cnt < n-1)
	  lr[row_cnt][col_cnt] -= lr[row_cnt+1][col_cnt+1];
      }

    int max_sum = -100 * n * n;
    for (int i=0; i < n; i++)
      for (int j=0; j < n; j++)
    	for (int k=i; k < n; k++)
    	  for (int l=j; l < n; l++) {
	    // case 1
    	    int total = ul[k][l];
    	    if (i > 0)
    	      total -= ul[i-1][l];
    	    if (j > 0)
    	      total -= ul[k][j-1];
    	    if (i > 0 && j > 0)
    	      total += ul[i-1][j-1];
	    max_sum = max (max_sum, total);

	    // case 2
	    if (k > i && l > j) {
	    total = ul[i][n-1];
	    if (l>0)
	      total -= ul[i][l-1];
	    total += ul[i][j];
	    total += lr[k][0];
	    if (j < n-1)
	      total -= lr[k][j+1];
	    total += lr[k][l];
	    max_sum = max(max_sum, total);
	    }

	    // case 3
	    if (k > i) {
	    total = ul[i][l];
	    if (j>0)
	      total -= ul[i][j-1];
	    total += lr[k][j];
	    if (l < n-1)
	      total -= lr[k][l+1];
	    max_sum = max(max_sum, total);
	    }

	    // case 4
	    if (l > j) {
	    total = ul[k][j];
	    if (i>0)
	      total -= ul[i-1][j];
	    total += lr[i][l];
	    if (k < n-1)
	      total -= lr[k+1][l];
	    max_sum = max(max_sum, total);
	    }
    	  }

    if (max_sum < 0)
      cout << 0 << endl;
    else
      cout << max_sum << endl;
  }
  return 0;
}
