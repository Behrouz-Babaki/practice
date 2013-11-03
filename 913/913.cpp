#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main(void){
  
  unsigned long int num;
  while (cin >> num){
  unsigned long int sum = (num + 1) * (num + 1) /4;
  cout << 6*sum - 9 << endl;
  }
  return 0;
}
