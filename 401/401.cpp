#include <iostream>
#include <string>
#include <map>
using namespace std;

bool isPalindrome(const string&);
bool isMirrored(const string& , const map<char,char>&);

int main (void){

   char letters[] = {'E' , 'J' , 'L' , 'S', 'Z' , '2' , '3' , '5'};
   char reverse[] = {'3' , 'L' , 'J' , '2' , '5' , 'S' , 'E' , 'Z'};
   char self[] = {'A' , 'H' , 'I' , 'M' , 'O' , 'T' , 'U' , 'V' , 'W', 'X' , 'Y' , '1' , '8'};

   map<char,char> reverses;

   for (int counter = 0 ; counter < 8 ; counter++)
      reverses.insert(pair<char,char>(letters[counter] , reverse[counter]));
   for (int counter = 0 ; counter < 13 ; counter++)
      reverses.insert(pair<char,char>(self[counter] , self[counter]));

  
  while (cin.good())
  {
    string str;
    getline(cin,str);
    int result = checkSentence(str);
    
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


bool isPalindrome(const string& givenStr){
   return false;
}

bool isMirrored(const string& givenStr , const map<char,char>& reverses){
   return false;
}
