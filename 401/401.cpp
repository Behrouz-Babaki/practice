#include <iostream>
#include <string>
#include <map>
#include <utility>

using std::map;
using std::string;
using std::endl;
using std::cout;
using std::cin;
using std::getline;
using std::pair;
using std::make_pair;

bool isPalindrome(const string&);
bool isMirrored(const string&);
int checkSentence(const string&);
map<char,char> reverses;

int main (void){

   char letters[] = {'E' , 'J' , 'L' , 'S', 'Z' , '2' , '3' , '5'};
   char reverse[] = {'3' , 'L' , 'J' , '2' , '5' , 'S' , 'E' , 'Z'};
   char self[] = {'A' , 'H' , 'I' , 'M' , 'O' , 'T' , 'U' , 'V' , 'W', 'X' , 'Y' , '1' , '8'};
   for (int counter = 0 ; counter < 8 ; counter++)
      reverses.insert(make_pair(letters[counter] , reverse[counter]));
   for (int counter = 0 ; counter < 13 ; counter++)
      reverses.insert(make_pair(self[counter] , self[counter]));

   string str;
   while (getline(cin, str))
  {
    int result = checkSentence(str);
    cout << str;
    switch (result){
    case 0: 
      cout << " -- is not a palindrome." << endl;
      break;
    case 1:
      cout << " -- is a regular palindrome." << endl;
      break;
    case 2:
      cout << " -- is a mirrored string." << endl;
      break;
    case 3:
      cout << " -- is a mirrored palindrome." << endl;
      break;
    }
    cout << endl;
  }
  return 0;
}

int checkSentence(const string& givenStr) {
  bool palindrom = isPalindrome(givenStr);
  bool mirrored = isMirrored(givenStr);
  if (palindrom) {
    if (mirrored) 
      return 3;
    else 
      return 1;
  }
  else {
    if (mirrored)
      return 2;
    else
      return 0;
  }
  return -1;
}


bool isPalindrome(const string& givenStr){
  bool palindrom = true;
  for (size_t counter = 0, size = givenStr.length(); 
       palindrom && counter < size/2; counter++)
    if (givenStr.at(counter) != givenStr.at(size-1-counter))
      palindrom = false;
   return palindrom;
}

bool isMirrored(const string& givenStr){
  bool mirrored = true;
  for (size_t counter = 0, size = givenStr.length();
       mirrored && counter < size/2; counter++) 
    if (reverses.find(givenStr.at(counter)) == reverses.end() ||
	givenStr.at(size-1-counter) != reverses[givenStr.at(counter)])
      mirrored = false;

  if (givenStr.length()%2 != 0) {
    char middle = givenStr.at(givenStr.length()/2);
    mirrored = mirrored && (reverses.find(middle) != reverses.end() &&
  			   middle == reverses[middle]);
  }
   return mirrored;
}
