#include <iostream>
#include <map>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::map;
using std::vector;

int main (void){
  map<int, int> numMap;
  vector<int> reps;
  vector<int> nums;
  int val;
  while (cin >> val){
    map<int,int>::iterator itr = numMap.find(val);
    if (itr == numMap.end()){
      reps.push_back(1);
      int index = reps.size() - 1;
      numMap[val] = index;
      
      nums.push_back(val);
    }
    else
      reps[itr->second]++;
  }

  for (vector<int>::iterator itr = nums.begin(), endItr = nums.end(); itr != endItr; itr++){
    cout << *itr << " ";
    int index = numMap.find(*itr)->second;
    cout << reps[index] << endl;
  }
  
  return 0;
}
