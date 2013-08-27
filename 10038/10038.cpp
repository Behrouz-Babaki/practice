#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>

int main (void){
  std::string str;
  std::istringstream ss;
  
  while (std::getline(std::cin, str)){
    ss.clear();
    ss.str(str);
    
    bool jolly = true;
    
    int length;
    ss >> length;

    int * sequence = new int[length - 1];
    for (int counter = 0; counter < length - 1; counter++)
      sequence[counter] = 0;

    int val;
    int prevVal;
    ss >> prevVal;
    ss >> val;

    int diff = std::abs (prevVal - val);
      
    for (int counter = 0; counter < length - 2; counter++){

      if (diff >= length || sequence[diff] == 1){
	jolly = false;
	break;
      }
      
      sequence [diff] = 0;
      prevVal = val;
      ss >> val;
      diff = std::abs (prevVal - val);
    }

    if (diff >= length || sequence[diff] == 1)
      jolly = false;

    std::cout << jolly << std::endl;
    delete sequence;
  }
  return 0;
}
