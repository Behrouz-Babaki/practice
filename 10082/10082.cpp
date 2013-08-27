#include <iostream>
#include <sstream>
#include <string>
#include <map>

int main (void){
  
  std::string str ("`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./");
  std::map <char, int> charMap;
  
  for (int counter = 0; counter < str.size(); counter++)
    charMap[str.at(counter)] = counter;
  
  std::string line;
  while (std::getline(std::cin , line)){
    for (int counter = 0 , size = line.length(); counter < size; counter++)
      if (line.at(counter) == ' ')
	std::cout << ' ';
      else
	{
	  int val = charMap.find(line.at(counter)) -> second;
	  std::cout << str [val-1];
	}
    std::cout << std::endl;
  }
    
  return 0;
}
