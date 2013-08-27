#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::getline;
using std::skipws;
using std::stringstream;
using std::string;
using std::vector;

int compare (const string&, const string&);
bool containsDigit (string::const_iterator, string::const_iterator);
bool isDigit (char);

int main (void){

  string line;
  getline (cin , line);
  
  stringstream ss (line);
  int val;
  ss >> val;
  
  int runNumber = 0;
  while (val != 0)
    {
      runNumber++;
      string correct;
      for (int counter = 0; counter < val; counter++){
	getline(cin, line);
	correct += '\n';
	correct += line;
      }
	
      getline(cin,line);
      ss.clear();
      ss.str(line);
      ss >> val;
      
      string submitted;
      for (int counter = 0; counter < val; counter++){
	getline(cin, line);
	submitted += '\n';
	submitted += line;
      }

      int result = compare (correct, submitted);
      cout << "Run #" << runNumber << ": ";
      switch (result){
      case 1: 
	cout << "Accepted";
	break;
      case 2: 
	cout << "Presentation Error";
	break;
      case 3:
	cout << "Wrong Answer";
	break;
      }
      cout << endl;
      
      getline(cin, line);
      ss.clear();
      ss.str(line);
      ss >> val;
    }

  return 0;
}

int compare (const string&first, const string&second){
  int returnValue = 1;
  string::const_iterator itr1, itr2;

  for (itr1 = first.begin(), itr2 = second.begin(); itr1 != first.end() && itr2 != second.end(); itr1++, itr2++)
    if (*itr1 != *itr2)
      {
      if (isDigit(*itr1) && isDigit(*itr2))
	returnValue = 3;
      else
	returnValue = 2;

      break;
      }
  
  if (returnValue == 2)
    while (itr1!= first.end() && itr2 != second.end())
      if (isDigit(*itr1) && isDigit(*itr2))
	{
	  if (*itr1 == *itr2)
	    {
	      itr1++;
	      itr2++;
	    }
	  else
	    {
	      returnValue = 3;
	      break;
	    }
	}
      else if (!isDigit(*itr1))
	itr1++;
      else
	itr2++;

  if (returnValue != 3 && (itr1 != first.end() || itr2 != second.end()))
    {
      returnValue = 2;
      if (itr1 == first.end() && containsDigit(itr2, second.end()))
	returnValue = 3;
      else if (itr2 == second.end() && containsDigit(itr1, first.end()))
	returnValue = 3;
    }
    
  return returnValue;
}

bool isDigit (char c)
{
  int code = static_cast<int> (c);
  return (code >= 48 && code <=57);
}


bool containsDigit (string::const_iterator itr, string::const_iterator end){

  for (; itr!= end; itr++)
    if (isDigit(*itr))
      return true;

  return false;
}
