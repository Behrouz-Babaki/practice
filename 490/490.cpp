#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main (void){
  int maxLength = 0;
  string str;
  vector<string> strVec;
  
  getline(cin , str);
  while (cin.good())
    {
      if (str.length() > maxLength )
	maxLength = str.length();

      strVec.push_back(str);

      getline(cin , str);
    }

  for (int column = 0 ; column < maxLength ; column ++)
    {
      for (int row = 0 ; row < strVec.size() ; row++)
	if (strVec[row].length() > column)
	  cout << strVec[row].at(column);
	else
	  cout << " ";

      cout << endl;
    }
}










