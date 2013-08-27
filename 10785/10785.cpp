#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

void printName (int, vector<char>, vector<char>);

char consonants[] = {'J' , 'S' , 'B' , 'K', 'T', 'C', 
		    'L', 'D', 'M', 'V', 'N', 'W', 
		    'F', 'X', 'G', 'P' , 'Y', 'H', 
		    'Q', 'Z', 'R'};

char vowels[] = {'A', 'U', 'E', 'O', 'I'};

int main (void){

  vector<char> consVec, vowVec;
  consVec.assign(consonants, consonants + 21);
  vowVec.assign(vowels, vowels + 5);

  int number_of_cases;
  string str;
  getline (cin, str);
  istringstream sstr (str);
  sstr >> number_of_cases;
  
  for (int counter = 0; counter < number_of_cases; counter++){
    sstr.clear();
    getline(cin, str);
    sstr.str(str);
    
    int lenght;
    sstr >> lenght;

    cout << "Case " << counter + 1 << ": ";
    printName (lenght, consVec, vowVec);
    cout << endl;
  }

  return 0;
  
}

void printName (int length, vector<char> cons, vector<char> vow){

  char vowel, consonant;
  int vowCount = 0, consCount = 0;
  
  vector<char>::iterator consItr = cons.begin();
  vector<char>::iterator vowItr = vow.begin();

  vowel = * vowItr;
  consonant = *consItr;

  for (int counter = 0; counter < length; counter++){
    if (counter % 2 == 1) /* consonant */{
      consCount++;
      if (consCount > 5){
	consCount = 1;
	consItr ++;
	consonant = * consItr;
      }
      
      cout << consonant;
    }
    else{ /* vowel */
      vowCount++;
      if (vowCount > 21){
	vowCount = 1;
	vowItr ++;
	vowel = * vowItr;
      }
      
      cout << vowel;
    }
  }
   
}
