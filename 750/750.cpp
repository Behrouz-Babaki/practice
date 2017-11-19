#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using std::cin;
using std::endl;
using std::cout;
using std::vector;
using std::string;
using std::to_string;
using std::abs;
using std::setw;

void update_valid(vector< vector< bool > >& valid, int row, int col);
void search(vector< int >& sol, vector< vector< bool > >& valid, int col, int&);

int main(void) {
  int num_cases;
  cin >> num_cases;
  
  while (num_cases--) {
    int row, col;
    cin >> row >> col;
    vector< vector< bool> > valid(9, vector< bool >(9, true));
    valid[col] = vector< bool >(9, false);
    valid[col][row] = true;
    vector< int > sol;
    update_valid(valid, row, col);
    int counter = 0;
    cout << "SOLN       COLUMN" << endl;
    cout << " #      1 2 3 4 5 6 7 8\n" << endl;
    search(sol, valid, 1, counter);
    if (num_cases)
      cout << endl;
  }
  
  return 0;

    
}

void search(vector< int >& sol, vector< vector< bool > >& valid, int col, int& counter) {
  if (col == 9) {
    cout << setw(2) << ++counter;
    cout << "      ";
    for (int i=0; i<8; i++) {
      cout << sol[i];
      if(i<7)
	cout << " ";
    }
    cout << endl;
    return;
  }

  for (int i=1; i<=8; i++)
    if (valid[col][i]) {
      vector< vector< bool > > v0(valid);
      update_valid(valid, i, col);
      sol.push_back(i);
      search(sol, valid, col+1, counter);
      sol.pop_back();
      valid.assign(v0.begin(), v0.end());
  }
}


void update_valid(vector< vector< bool > >& valid, int row, int col) {
  for(int i=1; i<=8; i++)
    if (i != col) {
      valid[i][row] = false;
      int col_diff = abs(i-col);
      if (row - col_diff >= 1)
	valid[i][row - col_diff] = false;
      if (row + col_diff <= 8)
	valid[i][row + col_diff] = false;
  }
}
