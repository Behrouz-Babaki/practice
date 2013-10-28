#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main(void){
  unsigned long int a[5001];
  a[0] = 0;
  a[1] = 1;
  for (int counter = 2; counter <= 5000; counter++)
    a[counter] = a[counter - 1] + a[counter - 2];

  int num;
  while (cin >> num)
    cout << "The Fibonacci number for " << num << " is " << a[num] << endl;

  return 0;
}
