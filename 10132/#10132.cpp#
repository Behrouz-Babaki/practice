#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <bitset>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::stringstream;
using std::skipws;
using std::ws;
using std::vector;
using std::bitset;

void createOriginalFile (const vector<vector<bool > > &);

int main (void){
  int number_of_cases, bla;
  cin >> number_of_cases >> ws;
  
  for (int counter = 0; counter < number_of_cases; counter++)
    {
      vector<vector<bool> > fragments;
      string line;
      getline(cin, line);

      while (!line.empty()){
	vector<bool> fragment;
	for (string::iterator itr = line.begin(), endItr = line.end(); itr != endItr; itr++)
	  fragment.push_back(((*itr) == '1' ? true : false));

	fragments.push_back(fragment);
	getline (cin, line);
      }
      
      createOriginalFile (fragments);
    }
  
  return 0;
}

void createOriginalFile (const vector<vector<bool> > & fragments){
}

/*
 * fragments: all fragments
 * possible_matches: for every fragment, an int vector of indices of other possible matches
 * matched: the indices of those which are matched
 * file: the pattern
 * We are assuming that all possible matches are initialized once
 */
bool checkNode (const vector<vector<bool> >& fragments, const vector<vector<int> >& possible_matches, vector<int>& matched, const vector<bool>& file){
  // If everything is matched, return true
  bool flag = true; 
  for (vector<int>::iterator itr = matched.begin() , flag && end = matched.end(); itr != end; itr++)
    if (*itr == -1)
      flag = false;

  if (flag) 
    return true;

  // for any of the unmatched fragments
  

  // for any of the possible matches for that fragment (which are not already matched)

  // for both directions (concatenation to right/left)
  
  // if the match works

  // mark the two as matched
  
  // call the function again

  // erase the marks
  
}
