#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::getline;
using std::string;
using std::ws;
using std::istringstream;

typedef vector<int> vi;
typedef vector<size_t> vs;
typedef vector<vs> vvs;

#define TRvvs(c, it) \
  for (vvs::iterator it = (c).begin(), eit = (c).end(); it != eit; it++)

#define TRvs(c, it) \
  for (vs::iterator it = (c).begin(), eit = (c).end(); it != eit; it++)

#define TRvi(c, it) \
  for (vi::iterator it = (c).begin(), eit = (c).end(); it != eit; it++)

void print_area(vvs&, size_t, size_t);

int main(void) {
  size_t number_of_cases;
  cin >> number_of_cases >> ws; 
  string line;
  getline(cin, line);
  
  for (size_t case_cnt = 0; case_cnt < number_of_cases; case_cnt++) {
    vvs land;
    getline(cin, line);
    while (line.at(0) == 'L' || line.at(0) == 'W') {
      vs row_vec;
      for (string::iterator it = line.begin(); it != line.end(); it++)
	row_vec.push_back (*it == 'L');
      land.push_back(row_vec);
      getline(cin, line);
    }
    istringstream ss(line);
    size_t row, col;
    ss >> row >> col;
    while (!ss.fail()) {
      print_area(land, row, col);
      getline(cin, line);
      ss.clear();
      ss.str(line);
      ss >> row >> col;
    }
  }

  return 0;
}

void print_area(vvs& land, size_t row, size_t col){
}
