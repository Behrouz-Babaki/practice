#include <iostream>
#include <string>
#include <cmath>

using std::cout;
using std::cin;
using std::ws;
using std::endl;
using std::string;

int getDecimal (const string&);
int gcd (int, int);

int main(void){
  size_t number_of_cases;
  cin >> number_of_cases >> ws;
  for (int caseCounter = 0; caseCounter < number_of_cases; caseCounter++){
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    int first = getDecimal (str1);
    int second = getDecimal (str2);
    bool flag = true;

    if (gcd(first, second) > 1)
      cout << "Pair #" << caseCounter + 1 << ": All you need is love!" << endl;
    else
      cout << "Pair #" << caseCounter + 1 << ": Love is not all you need!" << endl;
    
  }
  return 0;
}

int getDecimal (const string& str){
  int result = 0, counter = 0;
  for (string::const_reverse_iterator itr = str.rbegin() , endItr = str.rend(); itr != endItr; itr++, counter++){
    int ch = (int) (*itr);
    ch -= 48;
    result += ch * pow(2,counter);
}
  return result;
}


int gcd(int first, int second){
  int larger, smaller;
  if (first > second){
    larger = first;
    smaller = second;
  }
  else{
    smaller = first;
    larger = second;
  }
  
  while (smaller != 0){
    int temp = smaller;
    smaller = larger % smaller;
    larger = temp;
  }
  
  return larger;
}
