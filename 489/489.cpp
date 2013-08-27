#include <iostream>
#include <string>
#include <cstdlib>
#include <set>
using namespace std;

int decide(string& , string&);

int main(void){
  string messages[3] = {"win" , "lose" , "chickened out"};
  
  string str;
  getline(cin , str);
  int round = atoi(str.c_str());
  
  while(round != -1){
    string pattern , guess;
    getline(cin , pattern);
    getline(cin , guess);
    
    int result = decide(pattern , guess);
    cout << "Round " << round << endl;
    cout << "You " << messages[result] << "." <<  endl;

    getline(cin , str);
    round = atoi(str.c_str());
  }

}


int decide(string& pattern, string& guess){
  set<int> patternChars;
  set<int> guessChars;
  
  for (string::iterator itr = pattern.begin() ; itr != pattern.end() ; itr++)
    patternChars.insert((int) (*itr));

  bool done = false;
  int result;
  int mistakes = 0;

  string::iterator itr = guess.begin();

  while (!done){
    int  c = (int)(*itr);
    // processing the next guessed character
    if(guessChars.find(c) == guessChars.end()){
      set<int>::iterator position = patternChars.find(c);
      if (position != patternChars.end())
	patternChars.erase(c);
      else
	mistakes ++;
      
      guessChars.insert(c);
    }
    
    itr ++;
    if (mistakes == 7)
      {
	done = true;
	result = 1;
      }
    
    else if (patternChars.empty())
      {
	done = true;
	result = 0;
      }

    else if (itr == guess.end())
      {
	done = true;
	result = 2;
      }
  }

  return result;
}
