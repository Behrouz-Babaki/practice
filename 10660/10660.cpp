#include <iostream>
#include <utility>
#include <vector>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::make_pair;
using std::vector;
using std::abs;

typedef pair<int,int> ii;
typedef pair<ii, int> iii;

class centers{
public:
  centers(int c1, int c2, int c3, int c4, int c5) {
    cnts[0] = c1, cnts[1] = c2, cnts[2] = c3, cnts[3] = c4, cnts[4] = c5;
  }
  int cnts[5];
  void print() {
    for (int counter =  0; counter < 4; counter++)
      cout << cnts[counter] << " ";
    cout << cnts[4] << endl;
  }
  
};

int get_total(const centers&, const vector<iii>);

int main(void) {
  int num_cases;
  cin >> num_cases;
  while (num_cases--) {
    int num_regions;
    cin >> num_regions;
    vector<iii> regs;
    regs.reserve(num_regions);
    while (num_regions--) {
      int row, col, pop;
      cin >> row >> col >> pop;
      iii reg = make_pair(make_pair(row,col), pop);
      regs.push_back(reg);
    }

    centers best_centers(0,1,2,3,4);
    int min_total = get_total(best_centers, regs);
    
    for (int cnt1 = 0; cnt1 < 25; cnt1++)
      for (int cnt2 = cnt1+1; cnt2 < 25; cnt2++)
	for (int cnt3 = cnt2+1; cnt3 < 25; cnt3++)
	  for (int cnt4 = cnt3+1; cnt4 < 25; cnt4++)
	    for (int cnt5 = cnt4+1; cnt5 < 25; cnt5++){
	      centers current_centers(cnt1, cnt2, cnt3, cnt4, cnt5);
	      int current_total = get_total(current_centers, regs);
	      if (current_total < min_total){
		  best_centers = current_centers;
		  min_total = current_total;
	      }
	    }
    //cout << "min_total:" << min_total << endl;
    best_centers.print();
	      
  }
  return 0;
}

int get_total(const centers& cnt, const vector<iii> regs) {
  int total = 0;
  for (auto reg : regs) {
    int row = reg.first.first;
    int col = reg.first.second;
    int pop = reg.second;
    
    int min = abs(row-cnt.cnts[0]/5) + 
      abs(col-cnt.cnts[0]%5);
    int id = 0;
    for (int i = 1; i < 5; i++) {
      int r = cnt.cnts[i]/5;
      int c = cnt.cnts[i]%5;
      int dist = abs(row-r) + abs(col-c);
      if ( dist < min) {
	id = i;
	min = dist;
      }
    }
    total += min*pop;
  }
  return total;
}
