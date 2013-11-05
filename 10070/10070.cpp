#include <iostream>
#include <string>
#include <deque>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::deque;


bool isBigger(const deque<unsigned int>&, const deque<unsigned int>&);
bool isDivByEleven(const deque<unsigned int>&);
bool isDivByThree(const deque<unsigned int>& number);
void vecSum (deque<unsigned int>& number , unsigned int summand);
void vecDiff(const deque<unsigned int>& first, const deque<unsigned int>& second, deque<unsigned int>& result);
void convertToDeque(const string&, deque<unsigned int>&);
void printDeq(const deque<unsigned int>& d);

int main(void){
  string line;
  while (getline(cin,line)){
    bool divByFour = false, divByHundred = false, divByEleven = false, divByFive = false, divByThree = false, divByFH = false;
    
    deque<unsigned int> numDeque;
    //TODO implement the function
    convertToDeque(line, numDeque);
    
    if (isDivByThree(numDeque))
      divByThree = true;
    
    if (isDivByEleven(numDeque))
      divByEleven = true;

    int last = (int)(line.at(line.length() - 1) - 48);
    int prev = (int)(line.at(line.length() - 2) - 48);
    int threeToEnd = (int)(line.at(line.length() - 3) - 48);
    int fourToEnd = (int)(line.at(line.length() - 4) - 48);

    int lastTwo = prev * 10 + last;
      
    if (lastTwo % 4 == 0)
      divByFour = true;

    if (last == 0 || last == 5)
      divByFive = true;

    if (lastTwo == 0){
      divByHundred = true;

      int n =  fourToEnd * 10 + threeToEnd;
      if (n % 4 == 0)
	divByFH = true;
    }


    bool leap = false, huluculu = false, bulukulu = false;
    if (divByFour && !divByHundred)
      leap = true;
    if (divByFH)
      leap = true;
    if (divByThree && divByFive)
      huluculu = true;
    if (leap && divByFive && divByEleven)
      bulukulu = true;
    
    if (leap)
      cout << "This is leap year." << endl;
    if (huluculu)
      cout << "This is huluculu festival year." << endl;
    if (bulukulu)
      cout << "This is bulukulu festival year." << endl;
    
    if (!leap && !huluculu && !bulukulu)
      cout << "This is an ordinary year." << endl;

    cout << endl;
  }
  return 0;
}

bool isDivByThree(const deque<unsigned int>& number){

    if (number.size() == 1){
      if (number[0] == 3 || number[0] == 6 || number[0] == 9)
	return true;
      else
	return false;
    }

    deque<unsigned int> total;

    for (deque<unsigned int>::const_iterator itr = number.begin(), endItr = number.end() ; itr != endItr; itr++)
      vecSum(total, *itr);
     
    if (isDivByThree(total))
      return true;

    return false;
}

void vecSum (deque<unsigned int>& number , unsigned int summand){
  if (number.empty())
    number.push_back(0);
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

  while (!result.empty() && result.front() == 0)
    result.pop_front();

  if (result.empty())
    result.push_back(0);
}

bool isDivByEleven(const deque<unsigned int>& number){
  if (number.size() == 1){
    if (number[0] == 0)
      return true;
    else
      return false;
  }

  bool isOdd = true;

  deque<unsigned int> odd;
  deque<unsigned int> even;

  for (deque<unsigned int>::const_iterator itr = number.begin(), endItr = number.end() ; itr != endItr; itr++, isOdd = !isOdd)
      {
	unsigned int digit = *itr;

	if (isOdd)
	  vecSum(odd, digit);
	else 
	  vecSum(even, digit);
      }
  deque<unsigned int> diff;
  if (isBigger(odd, even))
    vecDiff(odd, even, diff);
  else 
    vecDiff(even, odd, diff);

  if (isDivByEleven(diff))
    return true;
  
  return false;
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

void convertToDeque(const string& str, deque<unsigned int>& d){
  d.clear();
  for (string::const_iterator itr = str.begin(), endItr = str.end(); itr != endItr; itr++)
    d.push_back((int) (*itr) - 48);
}

void printDeq(const deque<unsigned int>& d){
  for (deque<unsigned int>::const_iterator itr = d.begin(), endItr = d.end(); itr != endItr; itr++)
    cout << *itr;
  cout << endl;

}
