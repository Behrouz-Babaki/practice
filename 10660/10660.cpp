#include <iostream>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::make_pair;
using std::vector;

typedef pair<int,int> ii;
typedef pair<ii, int> iii;

class centers{
public:
  centers(int c1, int c2, int c3, int c4, int c5) {
    cnt1 = c1, cnt2 = c2, cnt3 = c3, cnt4 = c4, cnt5 = c5;
  }
  int cnt1, cnt2, cnt3, cnt4, cnt5;
  void print() {
    cout << cnt1 << " " << cnt2 << " " << cnt3 << " " << cnt4 << " " << cnt5 << endl;
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
    vector<centers> cs;
    centers first_centers(0,1,2,3,4);
    int total = get_total(first_centers, regs);
    cs.push_back(first_centers);
    
    for (int cnt1 = 0; cnt1 < 25; cnt1++)
      for (int cnt2 = cnt1+1; cnt2 < 25; cnt2++)
	for (int cnt3 = cnt2+1; cnt3 < 25; cnt3++)
	  for (int cnt4 = cnt3+1; cnt4 < 25; cnt4++)
	    for (int cnt5 = cnt4+1; cnt5 < 25; cnt5++){
	      centers current_centers(cnt1, cnt2, cnt3, cnt4, cnt5);
	      int current_total = get_total(current_centers, regs);
		if (current_total < total){
		  cs.clear();
		  cs.push_back(current_centers);
		}
		else if (current_total == total)
		  cs.push_back(current_centers);
		  
	    }
    for (auto c : cs)
      c.print();
	      
  }
  return 0;
}

int get_total(const centers& cnt, const vector<iii> regs) {
  return 0;
}
