#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::endl;
using std::deque;

void vecDiff(const deque<unsigned int>& first, const deque<unsigned int>& second, deque<unsigned int>& result);
void vecSum (deque<unsigned int>& number , unsigned int summand);
void printDeq(const deque<unsigned int>& d);
void putInDeq(int, deque<unsigned int>&);
int putInInt(const deque<unsigned int>&);
bool isBigger(const deque<unsigned int>& first, const deque<unsigned int>& second);
bool isDivByThree(const deque<unsigned int>& number);
bool equiv(bool first, bool second);
void randTest(void);
void randTest2(void);
void randTest3(void);

int main (void){
  deque<unsigned int> test;
  test.push_back(5);
  cout << isDivByThree(test) << endl;
  // randTest3();
  // randTest2();
  // randTest();
  // int a = 2074929411;
  // int b = 1734748532;
  // deque<unsigned int> d1, d2, result;
  // putInDeq(a, d1);
  // putInDeq(b, d2);
  // printDeq(d1);
  // printDeq(d2);
  // vecDiff(d1,d2,result);
  // printDeq(result);
  // int res = putInInt(result);
  // cout << a - b << endl;
  // cout << res << endl;
  return 0;
}

void vecDiff(const deque<unsigned int>& first, const deque<unsigned int>& second, deque<unsigned int>& result){
  result.clear();
  /* Assumption: the first argument is larger than the second one */
  int carry = 0;
  bool finished = false;
  deque<unsigned int>::const_reverse_iterator secondItr = second.rbegin(), secondItrEnd = second.rend();
  for (deque<unsigned int>::const_reverse_iterator itr = first.rbegin(), endItr = first.rend(); itr != endItr; itr++){
    int sec  = 0;
    if(secondItr != secondItrEnd){
      sec = *secondItr;
      secondItr++;
    }
      int sub =  carry + sec;
      if (*itr >= sub){
	result.push_front(*itr - sub);
	carry = 0;
      }
      else {
	result.push_front(*itr + 10 - sub);
	carry = 1;
      }
  }

  while (result.front() == 0)
    result.pop_front();
}

void putInDeq(int val, deque<unsigned int>& d){
  d.clear();
  while (val > 0){
    d.push_front(val%10);
    val /= 10;
  }
}

int putInInt(const deque<unsigned int>& d){
  int result = 0;
  for (deque<unsigned int>::const_iterator itr = d.begin(), endItr = d.end(); itr != endItr; itr++)
    result = (result * 10) + (*itr);

  return result;
}

void printDeq(const deque<unsigned int>& d){
  for (deque<unsigned int>::const_iterator itr = d.begin(), endItr = d.end(); itr != endItr; itr++)
    cout << *itr;
  cout << endl;

}

void randTest(void){
  srand(time(NULL));

  for (int counter = 0; counter < 1000000; counter++){
    int val1 = rand(), val2; 
    do {
      val2 = rand();
    } while (val2 == val1);
      
    if (val1 < val2){
      int temp = val1;
      val1 = val2;
      val2 = temp;
    }
    
    deque<unsigned int> d1, d2, result;
    putInDeq(val1, d1);
    putInDeq(val2, d2);
    if (putInInt(d1) != val1 || putInInt(d2) != val2)
      cout << "Are you kiddin' me?" << endl;
    vecDiff(d1, d2, result);

    int res = putInInt(result);
    if (res != val1 - val2){
      cout << "val1: " << val1 << "\tval2:" << val2 << endl;
      cout << "res: " << res << "\tactual value:" << val1 - val2 << endl;
    }
  }

}

void vecSum (deque<unsigned int>& number , unsigned int summand){
  unsigned int carry = summand;
  for (deque<unsigned int>::reverse_iterator itr = number.rbegin(), endItr = number.rend(); carry > 0 && itr != endItr; itr++){
    int sum = *itr + carry;
    *itr = sum % 10;
    carry = sum / 10;
  }

  while (carry > 0){
    number.push_front(carry%10);
    carry /= 10;
  }
}

void randTest2(void){
  srand(time(NULL));

  for (int counter = 0; counter < 1000000; counter++){
    int val1 = rand();
      
    deque<unsigned int> d1, result;
    putInDeq(val1, d1);

    int summand = rand() % 10;
    vecSum(d1, summand);
    int res = putInInt(d1);

    if (res != val1 + summand){
      cout << "val1: " << val1 << "\tsummand:" << summand << endl;
      cout << "res: " << res << "\tactual value:" << val1 + summand << endl;
    }
  }

}

void randTest3(void){
  srand(time(NULL));

  for (int counter = 0; counter < 1000000; counter++){
    int val1 = rand();
    int val2 = rand();
    deque<unsigned int> d1, d2;
    putInDeq(val1, d1);
    putInDeq(val2, d2);
    bool deqRes = isBigger(d1,d2);
    bool res = (val1 > val2);

    if (!equiv(deqRes,res))
      cout << "val1:" << val1 << "\tval2:" << val2 << "\tdeqRes:" << deqRes << "\tres:" << res << endl;

  }

}

bool isBigger(const deque<unsigned int>& first, const deque<unsigned int>& second)
{
  if (first.size() > second.size())
    return true;

  if (first.size() < second.size())
    return false;

  deque<unsigned int>::const_iterator firstItr = first.begin(), firstItrEnd = first.end(), secondItr = second.begin(), secondItrEnd = second.end();
  for (; firstItr != firstItrEnd; firstItr++, secondItr++)
    if (*firstItr > *secondItr)
      return true;
    else if (*firstItr < *secondItr)
      return false;

  return false;
}

bool equiv(bool first, bool second){
  return ((first && second) || (!first && !second));
}

bool isDivByThree(const deque<unsigned int>& number){

  if (number.size() == 1){
    if (number[0] == 3 || number[0] == 6 || number[0] == 9)
      return true;
    else
      return false;
  }

    deque<unsigned int> total;
    total.push_back(0);

    for (deque<unsigned int>::const_iterator itr = number.begin(), endItr = number.end() ; itr != endItr; itr++)
      vecSum(total, *itr);
    

    if (isDivByThree(total))
      return true;

    printDeq(total);
    return false;
}
