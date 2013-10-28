#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;
using std::istringstream;
using std::set_intersection;
using std::min;

int main(void){
  string line1, line2;
  while (getline(cin, line1)){
    getline(cin, line2);
    istringstream s1(line1) , s2(line2);
    vector<int> first;
    do {
      int val;
      s1 >> val;
      if (!s1.fail())
	first.push_back(val);
    } while (s1.good());
    sort(first.begin(), first.end());

    vector<int> second;
    do {
      int val;
      s2 >> val;
      if (!s2.fail())
	second.push_back(val);
    } while (s2.good());
    sort(second.begin(), second.end());
    
    vector<int> intersection (min(first.size(), second.size()));
    vector<int>::iterator itr = 
      set_intersection(first.begin(), first.end(), second.begin(), second.end(), intersection.begin());
    intersection.resize(itr - intersection.begin());

    unsigned int size = intersection.size();
    if (size == first.size())
      if (first.size() == second.size())
	cout << "A equals B" << endl;
      else
	cout << "A is a proper subset of B" << endl;
    else if (size == second.size())
      cout << "B is a proper subset of A" << endl;
    else if (size == 0)
      cout << "A and B are disjoint" << endl;
    else
      cout << "I'm confused!" << endl;
  }
  return 0;
}
