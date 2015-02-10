#include <iostream>
#include <queue> 

using std::endl;
using std::cout;
using std::cin;
using std::queue;

int main(void) {
  size_t n1, n2;
  cin >> n1 >> n2;
  while (n1 || n2) {
    queue<size_t> num1;
    while (n1) {
      num1.push(n1%10);
      n1 /= 10;
    }
    queue<size_t> num2;
    while (n2) {
      num2.push(n2%10);
      n2 /= 10;
    }
	
    size_t carry = 0;
    size_t carry_count = 0;
    while(!num1.empty() || !num2.empty()) {
      size_t sum = 0;
      if (!num1.empty()) {
	sum += num1.front();
	num1.pop();
      }
      if (!num2.empty()) {
	sum += num2.front();
	num2.pop();
      }
      if (carry)
	sum += carry;

      carry = 0;
      if (sum >= 10) {
	carry = 1;
	carry_count++;
      }
    }
    switch(carry_count) {
    case 0:
      cout << "No carry operation." << endl;
      break;
    case 1:
      cout << "1 carry operation." << endl;
      break;
    default:
      cout << carry_count << " carry operations." << endl;
    }
    cin >> n1 >> n2;
  }
  return 0;
}
