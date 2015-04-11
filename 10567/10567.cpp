#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::endl;
using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::upper_bound;

int get_id(char ch);

int main(void){
  string bates;
  cin >> bates;
  vector<vector<int> > indices(52, vector<int>());
  //chk: correct indicing
  for (int i=0, size=bates.length(); i<size; i++)  {
    int id = (int)bates[i];
    if (id < 97)
      indices[id-65].push_back(i);
    else
      indices[id-97+26].push_back(i);
  }
  int num_queries;
  cin >> num_queries;
  for (int i=0; i<num_queries; i++) {
    string query;
    cin >> query;
    bool success = true;
    int first, current, prev;
    if (indices[get_id(query[0])].empty())
      success = false;
    else 
      first = indices[get_id(query[0])][0];
    prev = first;
    for (int j=1; success && j<query.size(); j++) {
      vector<int>::iterator itr = upper_bound(indices[get_id(query[j])].begin(), 
			  indices[get_id(query[j])].end(), prev);
      if (itr == indices[get_id(query[j])].end())
	success = false;
      else
	current = *itr;
      prev = current;
    }
    if (success)
      cout << "Matched " << first << " " << current << endl;
    else
      cout << "Not matched" << endl;
  }
  return 0;
}

int get_id(char ch) {
  if (ch < 'a')
    return ch-65;
  return ch-71;
}
