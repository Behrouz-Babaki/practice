#include <iostream>
#include <string>
#include <cmath>
using std::cout;
using std::endl;
using std::cin;
using std::string;

bool isSquare(const string&, unsigned int);

int main(void){
  string line;
  while (getline(cin, line)){
    if (line.length() == 1 && line.at(0) == '0')
      break;

    bool found = false;
    int base;
    for (base = 2; !found && base < 100; base++)
      if (isSquare(line, base)){
	found = true;
	cout << base << endl;
      }
    
  }

  return 0;
}

bool isSquare(const string&  line, unsigned int base){

  int i = 0;
  unsigned int dec = 0;
  for (string::const_reverse_iterator itr = line.rbegin(), endItr = line.rend(); itr != endItr; itr++, i++){
    unsigned int digit = (unsigned int) (*itr) - 48;
    if (digit >= base)
      return false;
    dec += digit * pow(base, i);
  }
  
  if (sqrt(dec) == (int) sqrt(dec))
    return true;

  return false;
}
