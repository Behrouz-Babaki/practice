#include <iostream>
#include <string>
#include <sstream>
#include <utility>
#include <vector>

using std::cin;
using std::endl;
using std::cout;
using std::endl;
using std::ws;
using std::vector;
using std::string;
using std::istringstream;
using std::pair;
using std::make_pair;

typedef pair<int,int> ii;
typedef vector<ii> vii;

#define TRvii(c,itr) \
  for (vii::iterator itr = (c).begin(); itr != (c).end(); itr++)

int main(void) {
  int m, n;
  while (cin >> m) {
    cin >> n >> ws;
    vector<vii> matrix (n);
    for (int row_cnt = 0; row_cnt < m; row_cnt++) {
      string line1, line2;
      getline(cin,line1);
      getline(cin,line2);
      istringstream ss1(line1), ss2(line2);
      int num_elements;
      ss1 >> num_elements;
      for (int elem_cnt = 0; elem_cnt < num_elements; elem_cnt++) {
	int col, value;
	ss1 >> col;
	ss2 >> value;
	matrix[col-1].push_back(make_pair(row_cnt, value));
      }
    }

    cout << n << " " << m << endl;
    for (int col = 0; col < n; col++) {
      cout << matrix[col].size();
      TRvii (matrix[col] , itr)
	cout << " " << itr->first + 1;
      cout << endl;
      TRvii (matrix[col] , itr) {
	if (itr != matrix[col].begin())
	  cout << " ";
	cout << itr->second;
      }
      cout << endl;
    }
  }
  return 0;
}
