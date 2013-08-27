#include<iostream>
#include<string>
using namespace std;

double wordCount (string);
bool isLetter(char);

int main (void){

  string str;
  getline(cin , str);
  
  while (cin.good()){

    double counter = wordCount (str);
    cout << counter << endl;

    getline(cin, str);
  }
  return 0;
}


bool isLetter(char c){
  return (c >= 'A' && c <= 'z');
}

double wordCount (string str){
  double _wordCoutn = 0;
  bool inWord = false;
  for (string::const_iterator i = str.begin() ; i != str.end() ; i++){
    if (!inWord && isLetter(*i)){
      inWord = true;
      _wordCoutn++;
    }
    else if (!isLetter(*i) && inWord)
      inWord = false;
  }

  return _wordCoutn;
      
}


















