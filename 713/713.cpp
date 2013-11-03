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
  int n;
  cin >> n >> ws;
  for (int counter = 0; counter < n; counter++)
    {
      cin >> ws;
      string line;
      getline(cin,line);
      vector<unsigned int> first, second;
      
      string::iterator itr= line.begin(), endItr = line.end();
      for (; !isspace(*itr); itr++)
	first.push_back((unsigned int) (*itr) - 48);
      
      while (isspace(*itr))
      itr ++;

      for (; itr != endItr; itr++)
	second.push_back((unsigned int) (*itr) - 48);

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

