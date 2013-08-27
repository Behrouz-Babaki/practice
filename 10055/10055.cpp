#include<iostream>
#include<string>
#include<sstream>
using namespace std;

unsigned long int diff(unsigned long int,unsigned long int);

int main (void){

  istringstream sstr;
  string str;

  unsigned long int val1 , val2;
  
  getline(cin , str);
  
  while (cin.good() && sstr.good()){
  
    sstr.str(str);
    sstr >> val1 >> val2;
    
    cout << diff(val1, val2) << endl;

    sstr.clear();
    getline(cin , str);
  }
  return 0;
}

unsigned long int diff(unsigned long int val1 , unsigned long int val2){

  if (val1 <= val2)
    return val2 - val1;

  return val1 - val2;

}







