#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int main (void){

  istringstream sstr;
  string str;

  int val1 , val2;
  
  getline(cin , str);
  
  while (cin.good() && sstr.good()){
  
    sstr.str(str);
    sstr >> val1 >> val2;
    
    cout << 2 * val1 * val2 << endl;

    sstr.clear();
    getline(cin , str);
  }
  return 0;
}
