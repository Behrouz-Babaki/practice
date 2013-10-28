#include <iostream>
#include <vector>
#include <stack>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::stack;

#define MAX 5000

void sumUp(const vector<unsigned char>&, const vector<unsigned char>&, vector<unsigned char>&);

int main(void){
  vector<vector<unsigned char> > nums;

  vector<unsigned char> zero;
  zero.push_back(0);
  nums.push_back(zero);

  vector<unsigned char> one;
  one.push_back(1);
  nums.push_back(one);

  for (int counter = 2; counter <= MAX; counter++){
      vector<unsigned char> next;
      sumUp(nums[counter - 1], nums[counter - 2], next);
      nums.push_back(next);
    }

  int val;
  while (cin >> val){
    vector<unsigned char>& vec = nums[val];
    cout << "The Fibonacci number for " << val << " is ";
    for (vector<unsigned char>::iterator itr = vec.begin(), endItr = vec.end(); itr != endItr; itr++)
      cout << (unsigned int) (*itr);
    cout << endl;
  }

  return 0;
}


void sumUp(const vector<unsigned char>& first, const vector<unsigned char>& second, vector<unsigned char>& result){

  result.clear();
  stack<unsigned char> res;
  unsigned char carry = 0;
  vector<unsigned char>::const_reverse_iterator itr1 = first.rbegin(), itr2 = second.rbegin(), itr1End = first.rend(), itr2End = second.rend();
  for ( ;itr1 != itr1End && itr2 != itr2End; itr1++, itr2++){
    unsigned char dig = *itr1 + *itr2 + carry;
    res.push(dig % 10);
    carry = dig / 10;
  }
  vector<unsigned char>::const_reverse_iterator itr, itrEnd;
  bool remaining = false;
  if (itr1 != itr1End){
    itr = itr1;
    itrEnd = itr1End;
    remaining = true;
  }
  if (itr2 != itr2End){
    itr = itr2;
    itrEnd = itr2End;
    remaining = true;
  }
  if (remaining)
    for (; itr!= itrEnd; itr++){
      unsigned char dig = *itr + carry;
      res.push(dig % 10);
      carry = dig / 10;
  }

  while (carry > 0){
    res.push(carry % 10);
    carry /= 10;
  }

  result.reserve(res.size());
  while (!res.empty()){
    result.push_back(res.top());
    res.pop();
  }
    
}
