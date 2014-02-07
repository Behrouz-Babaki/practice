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
using std::reverse;

void printSequence (vector<int>&, vector<int>::iterator, int);

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
    
    printSequence(pancakes, pancakes.begin(), 0);
    cout << "0" << endl;
  }

  return 0;
}

void printSequence (vector<int>& seq, vector<int>::iterator startItr, int startIndex){

  auto endItr = seq.end();

  if ((startItr + 1) == endItr)
    return;
  
  auto maxItr = startItr;
  int max = *startItr;
  int maxIndex = startIndex;

  int counter = startIndex;
  for (auto itr = startItr; itr != endItr; counter++, itr++)
      if (*itr > max){
	max = *itr;
	maxIndex = counter;
	maxItr = itr;
      }

  if (maxIndex != startIndex){
    cout << maxIndex + 1 << " ";
    reverse (maxItr, endItr);
    reverse (startItr, endItr);
  }
  
  startItr++;
  startIndex++;
  printSequence (seq, startItr, startIndex);

  return;
}
