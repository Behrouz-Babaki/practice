#include <iostream>
#include <iomanip>
#include <utility>
#include <set>

using std::cout;
using std::endl;
using std::cin;
using std::setw;
using std::set;
using std::pair;

#define MAX_X 10000
#define MAX_Y 10000

struct pairCompare {
  bool operator() (const pair<unsigned int, unsigned int>& left, const pair<unsigned int, unsigned int>& right) const{

    if (left.first < right.first)
      return true;
    else if (left.first == right.first)
      return (left.second <= right.second); /* The equality should not happen */

    return false;
  }
};

typedef set<pair<unsigned int, unsigned int> , pairCompare > pairSet;

struct lineCompare{
  bool operator() (const pairSet& left, const pairSet& right) const
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
void findLines (const pairSet &, const pairSet&,  lineSet&);

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

  for (auto itr = instanceData.begin(), endItr = instanceData.end(); itr != endItr; itr++){

    findLines(instanceData, current, current_lines);

    for (auto lineItr = current_lines.begin(), lineItrEnd = current_lines.end(); lineItr != lineItrEnd; lineItr++){
      for (auto pointItr = lineItr->begin(), pointItrEnd = lineItr->end(); pointItr != pointItrEnd; pointItr++)
	cout << "(" << setw(4) << pointItr->first << "," << setw(4) << pointItr->second << ")";
      cout << endl;
    }
  }
  
  return;
}

/* find all the lines in the dataset that contain this point */
void findLines (const pairSet &instanceData, const pairSet &current,  lineSet &current_lines){
  current_lines.clear();
  for (auto pairItr = current.begin(), pairItrEnd = current.end(); pairItr != pairItrEnd; pairItr++)
    {
      pair<unsigned int, unsigned int> point = *pairItr;
      for (int xinc = -1; xinc <= 1; xinc++){
	int x = point.first + xinc;
	if (x < 0 || x > MAX_X)
	  continue;

	pairSet current_line;
	for (int yinc = -1; yinc <= 1; yinc++)
	  {
	    int y = point.second + yinc;
	    if (xinc == 0 && yinc == 0 || y < 0 || y > MAX_Y)
	      continue;

	    pair<unsigned int, unsigned int> otherPoint (x,y);
	    if (instanceData.find(otherPoint) != instanceData.end())
	      current_line.insert(otherPoint);
	  }

	if (!current_line.empty())
	  current_lines.insert(current_line);
      }
    }

  return;
}

