#include <iostream>
#include <deque>
using std::cout;
using std::endl;
using std::cin;
using std::deque;

bool palindrome(unsigned int);
unsigned int reverse(unsigned int);

int main(void){
  int number_of_cases;
  cin >> number_of_cases;
  for (int counter = 0; counter < number_of_cases; counter++){
    unsigned int number;
    cin >> number;
    int count = 0;
    while(!palindrome(number)){
      number += reverse(number);
      count++;
    }
    cout << count << " " << number << endl;
  }
  return 0;
}

bool palindrome(unsigned int number){
  deque<int> digits;
  while (number > 0){
    digits.push_back(number%10);
    number /= 10;
  }
  
  bool finished = false;
  while (!finished && digits.size() >= 2){
    int first = digits.front();
    int last = digits.back();
    digits.pop_back();
    digits.pop_front();
    if (first != last)
      finished = true;
  }
  
  return !finished;
}

unsigned int reverse(unsigned int number){
  unsigned int reversedNum = 0;
  while (number > 0){
    reversedNum *= 10;
    reversedNum += (number%10);
    number /= 10;
  }
  return reversedNum;
}
