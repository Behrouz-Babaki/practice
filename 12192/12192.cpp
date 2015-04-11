#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main(void) {
  int rows, cols;
  cin >> rows >> cols;
  while (rows && cols){
    vector<vector<int> > table(rows, vector<int>(cols));
    for (int i=0; i<rows; i++)
      for (int j=0; j<cols; j++)
	cin >> table[i][j];
    //pre-process here
    vector<vector<int> > diags;
    for (int i=0; i<rows; i++) {
      vector<int> diag;
      int r = i;
      int c = 0; 
      while (r < rows && c < cols)
	diag.push_back(table[r++][c++]);
      diags.push_back(diag);
    }

    for (int i=1; i<cols; i++) {
      vector<int> diag;
      int r = 0;
      int c = i; 
      while (r < rows && c < cols)
	diag.push_back(table[r++][c++]);
      diags.push_back(diag);
    }
      
    int q;
    cin >> q;
    while (q--) {
      int l, u;
      cin >> l >> u;
      // answer here
    }
    cout << '-' << endl;
    cin >> rows >> cols;
  }
  return 0;
}
