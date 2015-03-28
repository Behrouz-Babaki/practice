#include <iostream>
#include <string>
#include <vector>
#include <set>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;
using std::set;

int main(void) {
  int num_cases;
  cin >> num_cases;
  while (num_cases--) {
    vector<set<int> > left(3);
    vector<set<int> > right(3);
    int result[3];
    for (int i = 0; i < 3; i++){
      string first, second, third;
      cin >> first >> second >> third;

      for (int j = 0; j < first.length(); j++)
	left[i].insert(first[j] - 'A');

      for (int j = 0; j < second.length(); j++)
	right[i].insert(second[j] - 'A');

      if (!third.compare("even"))
	result[i] = 0;
      if (!third.compare("up"))
	result[i] = 1;
      if (!third.compare("down"))
	result[i] = 2;
    }
    bool found = false;
    int counterfeit = 0;
    while (!found) {
      for (int heavier = 0; !found && heavier < 2; heavier++) {
	found = true;
	for (int i = 0; found && i < 3; i++) {
	  bool in_left = (left[i].find(counterfeit) != left[i].end());
	  bool in_right = (right[i].find(counterfeit) != right[i].end());
	  int exp;
	  if ((in_left && in_right) ||
	      (!in_left && !in_right))
	    exp = 0;
	  if (in_left && !in_right)
	    exp = 2 - heavier;
	  if (!in_left && in_right)
	    exp = 1 + heavier;
	  if (exp != result[i])
	    found = false;
	}
	if (found) {
	  cout << (char) ('A' + counterfeit) << " is the counterfeit coin and it is ";
	  if (heavier)
	    cout << "heavy." << endl;
	  else
	    cout << "light." << endl;
	}
      } 
      counterfeit++;
    }
  }
  return 0;
}
