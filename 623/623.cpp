#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::stack;
using std::queue;

void printFact(const vector<vector<unsigned int> > &, int);
void createFact(vector<vector<unsigned int> > &, int, int);
void mult(const vector<unsigned int>&, const vector<unsigned int>&, vector<unsigned int>&);

int main (void){
  vector<vector<unsigned int> > vec;
  vec.push_back(vector<unsigned int>(1,1));
  int max = 1;

  int number;
  while (cin >> number){
    if (number <= max)
      printFact(vec, number);
    else{
      createFact(vec, number, max);
      printFact(vec, number);
      max = number;
    }
  }
  return 0;
}

void printFact(const vector<vector<unsigned int> > &vec, int number){
  cout << number << "!" << endl;
  for (vector<unsigned int>::const_iterator itr = vec[number - 1].begin(), itrEnd = vec[number - 1].end(); itr != itrEnd; itr++)
    cout << *itr;
  cout << endl;
}


void createFact(vector<vector<unsigned int> > &vec, int number, int max){
  unsigned int currentNum = max + 1;
  while (currentNum <= number)
  {
    stack<unsigned int> stackRep;
    unsigned int normRep = currentNum;
    while (normRep > 0){
      stackRep.push(normRep%10);
      normRep /= 10;
    }
    vector<unsigned int> vecRep;
    while (!stackRep.empty()){
      vecRep.push_back(stackRep.top());
      stackRep.pop();
    }
    vector<unsigned int> next;
    mult (vec[currentNum - 2] , vecRep, next);
    vec.push_back(next);
    currentNum++;
  }
  
}

void mult(const vector<unsigned int>& firstVec, const vector<unsigned int>& secondVec, vector<unsigned int>& resultVec){

  vector<queue<unsigned int> > constituents;
  int offset = 0;
  for (vector<unsigned int>::const_reverse_iterator itr = firstVec.rbegin(), endItr = firstVec.rend(); itr != endItr; itr++, offset++){
    queue<unsigned int> current; 
    for (int counter = 0; counter < offset; counter++)
      current.push(0);
    
    unsigned int m = *itr;
    unsigned int carry = 0;
    for (vector<unsigned int>::const_reverse_iterator itr2 = secondVec.rbegin(), endItr2 = secondVec.rend(); itr2 != endItr2; itr2++){
      unsigned int o = (*itr2) * m + carry;
      current.push(o % 10);
      carry = o /10;
    }

      while (carry > 0){
        current.push(carry%10);
        carry /= 10;
      }
    constituents.push_back(current);
  }

  bool finished = false;
  unsigned int carry = 0, sum = 0;
  stack<unsigned int> result;
  while (!finished){
    finished = true;
    sum = carry;
    for (vector<queue<unsigned int> >::iterator itr = constituents.begin(), endItr = constituents.end(); itr != endItr; itr++){
      if (!itr->empty()){
        sum += itr->front();
        itr->pop();
      }
      if (!itr -> empty())
        finished = false;
    }
    result.push(sum % 10);
    carry = sum / 10;
  }

    while (carry > 0){
      result.push(carry%10);
      carry /= 10;
    }
    
    /* removing trailing zeros */
    while (result.top() == 0)
      result.pop();


    resultVec.clear();
    resultVec.reserve(result.size());

    while (!result.empty()){
      resultVec.push_back(result.top());
      result.pop();
    }
}
