#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;
using std::ws;

int main(void){
 size_t n;
  cin >> n >> ws;
  for (size_t counter = 0; counter < n; counter++)
    {

      vector<unsigned int> first, second;

      int ch = cin.get();
      while (!isspace(ch)){
	first.push_back(ch - 48);
	ch = cin.get();
      }

      while(isspace(ch))
	ch = cin.get();

      while (!isspace(ch)){
	second.push_back(ch - 48);
	ch = cin.get();
      }

      unsigned int carry = 0;
      vector<unsigned int>::iterator firstItr , firstItrEnd, secondItr, secondItrEnd;
      firstItr = first.begin();
      secondItr = second.begin();
      firstItrEnd = first.end();
      secondItrEnd = second.end();
      
      vector<unsigned int> result;
      while (true){
	if (firstItr == firstItrEnd && secondItr == secondItrEnd)
	  break;
	unsigned int sum = carry;
	if (firstItr != firstItrEnd)
	  sum += (*(firstItr++));
	if (secondItr != secondItrEnd)
	  sum += (*(secondItr++));
	
	result.push_back(sum%10);
	carry = sum / 10;
      }

      while (carry > 0){
	result.push_back(carry % 10);
	carry /= 10;
      }

      for (vector<unsigned int>::iterator itr = result.begin(), endItr = result.end(); itr != endItr; itr++)
	if ((*itr) != 0)
	  cout << *itr;
      cout << endl;
    }
  return 0;
}

