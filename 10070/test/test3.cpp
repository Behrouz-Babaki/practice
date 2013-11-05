#include <iostream>
#include <ctime>
#include <cstdlib>

using std::cout;
using std::endl;

void printNumber(int);
int main(void)
{
  int number_of_cases = 100;
  for (int counter = 0; counter < number_of_cases; counter++){
    int length = rand()%10000;
    printNumber(length);
  }

  return 0;
}

void printNumber(int length){
  srand(time(NULL));
  for (int counter = 0; counter < length; counter++)
    cout << rand()%10;
  cout << endl;
}
