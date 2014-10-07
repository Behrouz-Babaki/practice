#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>

int main (void){
  std::string str;
  std::istringstream ss;
  
  while (std::getline(std::cin, str)){
    ss.clear();
    ss.str(str);
    
    bool jolly = true;
    
    int length;
    ss >> length;

    std::vector<bool> sequence (length-1, false);

    int val;
    int prevVal;
    ss >> prevVal;
    ss >> val;

    int diff = std::abs (prevVal - val);
      
    for (int counter = 0; jolly && counter < length - 2; counter++)
      if (diff >= length || diff == 0 || sequence[diff-1])
	jolly = false;
      else {
	sequence [diff-1] = true;
	prevVal = val;
	ss >> val;
	diff = std::abs (prevVal - val);
      }
    

    if (jolly)
      std::cout << "Jolly" << std::endl;
    else
      std::cout << "Not jolly" << std::endl;
  }
  return 0;
}
