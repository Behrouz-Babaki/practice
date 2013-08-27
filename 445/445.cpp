#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

void printMaze(string& );

int main (void)
{
  string str;
  getline(cin , str);
  while (cin.good()){
    if (str.empty())
      cout << endl;
    else
      printMaze(str);

    getline(cin , str);
  }

  return 0;
}

void printMaze(string & str){
  int count = 0;
  for (string::iterator itr = str.begin() ; itr != str.end() ; itr++)
    if (*itr >= '0' && *itr <= '9')
      count += (int)(*itr) - (int)('0');
    else
      {
	if (*itr == '!')
	  cout << endl;
	else if (*itr == 'b')
	  for (int counter = 0 ; counter < count ; counter++)
	    cout << " ";
	
	else
	  for (int counter = 0 ; counter < count ; counter++)
	    cout << *itr;
	  
	count = 0;
      }

  cout  << endl;
}






