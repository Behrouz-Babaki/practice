#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::cin;
using std::string;

int main(void){
  string line;
  while (getline(cin,line)){
    bool divByFour = false, divByHundred = false, divByEleven = false, divByFive = false, divByThree = false, divByFH = false;
    int oddSum = 0;
    int evenSum = 0;
    bool isOdd = true;
    for (string::iterator itr = line.begin(), endItr = line.end(); itr != endItr; itr++, isOdd = !isOdd)
      {
	int digit = (int)(*itr) - 48;
	if (isOdd)
	  oddSum += digit;
	else 
	  evenSum += digit;
      }
    
    int sumDiff = oddSum - evenSum;
    if (sumDiff == 0 || sumDiff % 11 == 0)
      divByEleven = true;

    int sum = evenSum + oddSum;
    if (sum % 3 == 0)
      divByThree = true;

    int last = (int)(line.at(line.length() - 1) - 48);
    int prev = (int)(line.at(line.length() - 2) - 48);
    int threeToEnd = (int)(line.at(line.length() - 3) - 48);
    int fourToEnd = (int)(line.at(line.length() - 4) - 48);

    int lastTwo = prev * 10 + last;
      
    if (lastTwo % 4 == 0)
      divByFour = true;

    if (last == 0 || last == 5)
      divByFive = true;

    if (lastTwo == 0){
      divByHundred = true;

      int n =  fourToEnd * 10 + threeToEnd;
      if (n % 4 == 0)
	divByFH = true;
    }


    bool leap = false, huluculu = false, bulukulu = false;
    if (divByFour && !divByHundred)
      leap = true;
    if (divByFH)
      leap = true;
    if (divByThree && divByFive)
      huluculu = true;
    if (leap && divByFive && divByEleven)
      bulukulu = true;
    
    if (leap)
      cout << "This is leap year." << endl;
    if (huluculu)
      cout << "This is huluculu festival year." << endl;
    if (bulukulu)
      cout << "This is bulukulu festival year." << endl;
    
    if (!leap && !huluculu && !bulukulu)
      cout << "This is an ordinary year." << endl;

    cout << endl;
  }
  return 0;
}
