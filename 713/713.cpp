#include <iostream>
#include <string>
#include <vector>
#include <stack>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;
using std::stack;

int main(void){
  int n;
  cin >> n;
  for (int counter = 0; counter < n; counter++)
    {
      string line;
      getline(cin,line);
      vector<unsigned int> first, second;
      
      string::iterator itr, endItr;
      for (itr = line.begin(); *itr != ' '; itr++)
	first.push_back((unsigned int) (*itr) - 48);

      itr ++;

      for (endItr = line.end(); itr != endItr; itr++)
	second.push_back((unsigned int) (*itr) - 48);
      
      unsigned int carry = 0;
      vector<unsigned int>::iterator firstItr , firstItrEnd, secondItr, secondItrEnd;
      firstItr = first.begin();
      secondItr = second.begin();
      firstItrEnd = first.end();
      secondItrEnd = second.end();
      
      stack<unsigned int> result;
      while (true){
	if (firstItr == firstItrEnd && secondItr == secondItrEnd)
	  break;
	unsigned int sum = carry;
	if (firstItr != firstItrEnd)
	  sum += (*(firstItr++));
	if (secondItr != secondItrEnd)
	  sum += (*(secondItr++));
	
	result.push(sum%10);
	carry = sum / 10;
      }

      while (carry > 0){
	result.push(carry % 10);
	carry /= 10;
      }

      if (result.empty())
	cout << "Are you kidding me or what?" << endl;
      while(result.top() == 0)
	result.pop();

      while (!result.empty()){
	cout << result.top();
	result.pop();
      }
      cout << endl;
    }
  return 0;
}

