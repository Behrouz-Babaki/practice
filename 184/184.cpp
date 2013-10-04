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
using std::setprecision;

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


void printSet(const pairSet&);
void printResults (const pairSet&);
void findLines (const pairSet &, lineSet&);

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

    findLines(instanceData, lines);
    cout << "number of lines:" << lines.size() << endl;
    for (auto lineItr = lines.begin(), lineItrEnd = lines.end(); lineItr != lineItrEnd; lineItr++){
      for (auto pointItr = lineItr->begin(), pointItrEnd = lineItr->end(); pointItr != pointItrEnd; pointItr++)
	cout << "(" << setw(4) << pointItr->first << "," << setw(4) << pointItr->second << ")";
      cout << endl;
    }
    
  return;
}

/* find all the lines in the dataset that contain this point */
void findLines (const pairSet &instanceData,  lineSet &lines){

  lines.clear();
  for (auto firstPairItr = instanceData.begin(), pairItrEnd = instanceData.end(); firstPairItr != pairItrEnd; firstPairItr++){
    auto secondPairItr = firstPairItr;
    secondPairItr++;
    for (; secondPairItr != pairItrEnd; secondPairItr++)
      {
	pairSet current_line;
	current_line.insert(*firstPairItr);
	current_line.insert(*secondPairItr);

	for (auto candItr = instanceData.begin() , candItrEnd = instanceData.end(); candItr != candItrEnd; candItr++)
	  {
	    if (candItr == firstPairItr || candItr == secondPairItr)
	      continue;
	    
	    // /******************************/
	    // cout << "(" << firstPairItr->first << "," << firstPairItr->second << ")"
	    // 	 << " (" << secondPairItr->first << "," << secondPairItr->second << ")"
	    // 	 << " (" << candItr->first << "," << candItr->second << ")\t";
	    // /******************************/

	    if ((firstPairItr->first-secondPairItr->first)*(firstPairItr->second - candItr->second) == (firstPairItr->first - candItr->first)*(firstPairItr->second - secondPairItr->second))
	      current_line.insert(*candItr);

	  }

	if (current_line.size() > 2)
	  {
	    cout << "found a line" << endl;
	    lines.insert(current_line);
	  }
      }
  }
  cout << "lines found: " << lines.size() << endl;
  return;
}

void printSet(const pairSet& points){
  for (auto itr = points.begin(), endItr = points.end(); itr != endItr; itr++)
    cout << "(" << itr->first << "," << itr->second << ")\t";
  cout << endl;
}
