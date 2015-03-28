#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::min_element;
using std::max_element;

void find_sync(const vector<int>&);
int main(void) {
  int first, second, third;
  cin >> first >> second >> third;
  while (first || second || third) {
    vector<int> cycles;
    cycles.push_back(first);
    cycles.push_back(second);
    while (third) {
      cycles.push_back(third);
      cin >> third;
    }
    find_sync(cycles);
    cin >> first >> second >> third;
  }
  return 0;
}

void find_sync(const vector<int>& cycles){
  int current_time = *min_element(cycles.begin(), cycles.end()) * 2;
  int max_cycle = *max_element(cycles.begin(), cycles.end());
  bool found = false;
  while (!found && current_time <= 5 * 3600) {
    //cout << "current_time:" << current_time << endl;
    found = true;
    int min_next = max_cycle;
    int current_next;
    for (vector<int>::const_iterator itr = cycles.begin(); itr != cycles.end(); itr++) {
      int surplus = current_time % (2*(*itr));
      if (surplus >= (*itr-5))
	found = false;
      current_next = (2 * (*itr)) - surplus;
      if (current_next < min_next)
	min_next = current_next;
    }
    if (found) {
      int h = current_time / 3600;
      current_time %= 3600;
      int m = current_time / 60;
      current_time %= 60;
      if (h < 10)
	cout << "0";
      cout << h << ":";
      if (m < 10)
	cout << "0";
      cout << m << ":";
      if (current_time < 10)
	cout << "0";
      cout << current_time << endl;
    }
    else
      current_time += min_next;
  }
  if (!found)
    cout << "Signals fail to synchronise in 5 hours" << endl;
}
