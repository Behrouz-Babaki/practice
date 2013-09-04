#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::stringstream;
using std::string;
using std::vector;
using std::max_element;

void printSequence (const vector<int>&, vector<int>::const_iterator);

int main (void){
  string line;
  while (getline(cin, line)){
    stringstream ss (line);
    vector<int> pancakes;
    
    int next;
    ss >> next;
    while (ss){
      pancakes.push_back(next);
      ss >> next;
    }

    printSequence(pancakes, pancakes.begin());
  }

  return 0;
}

void printSequence (const vector<int>& seq, vector<int>::const_iterator startItr){

  if ((startItr + 1) == seq.end())
    return;
  
  cout << "0" << endl;


  return;
}
