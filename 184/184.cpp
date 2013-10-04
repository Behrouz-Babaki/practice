#include <iostream>
#include <utility>
#include <set>

using std::cout;
using std::endl;
using std::cin;
using std::set;
using std::pair;

struct pairCompare {
  bool operator() (const pair<unsigned int, unsigned int>& left, const pair<unsigned int, unsigned int>& right){

    if (left.first < right.first)
      return true;
    else if (left.first == right.first)
      return (left.second <= right.second); /* The equality should not happen */

    return false;
  }
};

typedef set<pair<unsigned int, unsigned int> , pairCompare > pairSet;

struct lineCompare{
  bool operator() (const pairSet& left, const pairSet& right)
  {
    /* assumption is that the sets are ordered */
    auto leftItr = left.begin(), rightItr = right.begin();
    if (leftItr->first == rightItr->first && leftItr->second == rightItr->second){
      leftItr++;
      rightItr++;
    }
    pairCompare pairCompareInstance;
    return (pairCompareInstance(*leftItr, *rightItr));
  }
};

typedef set<set<pair<unsigned int, unsigned int>,pairCompare >,lineCompare > lineSet;



void printResults (const pairSet&);
void findLines (const pairSet &, const pairSet&,  lineSet);

int main(void) {

  bool instance = true;
  bool series = true;
  int value;

  int x , y;
  cin >> x >> y;
  while (series) {
    if (x == 0 && y == 0)
      series = false;
    else
      {
	pairSet instanceData;
	while (instance){
	  if (x == 0 && y == 0)
	    instance = false;
	  else{
	    pair<unsigned int, unsigned int> value (x,y);
	    instanceData.insert(value);
	  }
	  cin >> x >> y;
	}
	printResults (instanceData);
	instance = true;
      }
  }

  return 0;
}

void printResults (const pairSet &instanceData)
{
  lineSet lines;
  pairSet current;
  lineSet current_lines;
  cout.width(4);
  for (auto itr = instanceData.begin(), endItr = instanceData.end(); itr != endItr; itr++){
    findLines(instanceData, current, current_lines);
    for (auto lineItr = current_lines.begin(), lineItrEnd = current_lines.end(); lineItr != lineItrEnd; lineItr++){
      for (auto pointItr = lineItr->begin(), pointItrEnd = lineItr->end(); pointItr != pointItrEnd; pointItr++)
	cout << "(" << pointItr->first << "," << pointItr->second << ")";
      cout << endl;
    }
  }
  
  return;
}

/* find all the lines in the dataset that contain this point */
void findLines (const pairSet &instanceData, const pairSet &current,  lineSet current_lines){
  current_lines.clear();
  current_lines.insert(current);
  return;
}

