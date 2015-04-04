#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::sort;
using std::setprecision;
using std::fixed;

int main(void) {
  int front_num, rear_num;
  cin >> front_num;

  while (front_num != 0) {
    cin >> rear_num;
    vector<double> front(front_num);
    for (int counter = 0; counter < front_num; counter++)
      cin >> front[counter];
    double diff;
    vector<double> rear(rear_num);
    for (int counter = 0; counter < rear_num; counter++)
      cin >> rear[counter];
    vector<double> ratios;
    ratios.reserve(front_num*rear_num);
    for (int f_counter = 0, f_size = front.size(); f_counter < f_size; f_counter++)
      for (int r_counter = 0, r_size = rear.size(); r_counter < r_size; r_counter++)
	ratios.push_back(rear[r_counter] / front[f_counter]);
    sort(ratios.begin(), ratios.end());
    diff = ratios[1] / ratios[0];
    for (int counter = 1, size = ratios.size(); counter < size; counter++)
      if (diff < ratios[counter] / ratios[counter-1])
	diff = ratios[counter] / ratios[counter-1];
    cout << setprecision(2) << fixed << diff << endl;
    cin >> front_num;
  }
  return 0;
}
