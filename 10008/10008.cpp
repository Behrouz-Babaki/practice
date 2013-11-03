#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using std::cout;
using std::endl;
using std::cin;
using std::ws;
using std::string;
using std::vector;
using std::pair;
using std::make_pair;

bool comp(const pair<int, int>&, const pair<int, int>&);
int main(void){
  int number_of_cases;
  vector<pair<int,int> > counts;
  for (int counter = 0; counter < 26; counter++){
    pair<int,int> p = make_pair(counter, 0);
    counts.push_back(p);
  }

  cin >> number_of_cases >> ws;
  for (int counter = 0; counter < number_of_cases; counter++){
    string line;
    getline(cin, line);
    for (string::iterator itr = line.begin(), endItr = line.end(); itr != endItr; itr++){
      int ch = (int) (*itr);
      if (ch >= 65 && ch <= 90)
	counts[ch-65].second ++;
      if (ch>= 97 && ch <= 122)
	counts[ch-97].second ++;
    }
  }

  stable_sort(counts.begin(), counts.end(), comp);
  for (vector<pair<int,int> >::iterator itr = counts.begin(), endItr = counts.end(); itr != endItr; itr++)
    if (itr-> second > 0)
      cout << (char) (itr->first + 65) << " " << itr-> second << endl;
  
  return 0;
}

bool comp(const pair<int, int>& left, const pair<int, int>& right){
  return left.second > right.second;
}
