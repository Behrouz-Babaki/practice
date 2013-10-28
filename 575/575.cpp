#include <iostream>
#include <stack>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::stack;

int main (void){

  while (true){
  char ch;
  stack<unsigned int> number;

  while (true){
    cin.get(ch);
    if (ch == 10)
      break;

    if (ch == '0')
      number.push(0);
    else if (ch == '1')
      number.push(1);
    else if (ch ==  '2')
      number.push(2);
  }

  if (number.size() == 1 && number.top() == 0)
    break;
  int sum = 0;
  for (int k = 0; !number.empty(); k++){
    sum += (pow(2, k+1) - 1) * number.top();
    number.pop();
  }
  cout << sum << endl;

  }
  

}
