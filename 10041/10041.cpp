#include <iostream>
#include <vector>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main(void)  {
  size_t num_cases;
  cin >> num_cases;
  for (size_t case_counter = 0; case_counter < num_cases; case_counter++) {
    size_t num_relatives;
    cin >> num_relatives;
    vector<size_t> streets (num_relatives);
    size_t total = 0;
    for (size_t relative_cnt = 0; relative_cnt < num_relatives; relative_cnt++) {
      cin >> streets[relative_cnt];
      total += streets[relative_cnt];
    }
    size_t avg1 = total / num_relatives;
    size_t avg2 = avg1 + 1;
    
    size_t t1 = 0, t2 = 0; 
    for (size_t relative_cnt = 0; relative_cnt < num_relatives; relative_cnt++) {
      int a1 = streets[relative_cnt] - avg1;
      t1 += (a1 > 0 ? a1 : -a1);
      int a2 = streets[relative_cnt] - avg2;
      t2 += (a2 > 0 ? a2 : -a2);
    }
    cout << (t1 > t2 ? t2 : t1) << endl;
  }
  return 0;
}
