#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using std::cout;
using std::endl;
using std::cin;
using std::getline;
using std::stringstream;
using std::string;
using std::vector;
using std::map;

/**
 * the quick brown fox jumps over the lazy dog
 * This sentence is consisted of 43 characters
 */

bool notBlank(string * const);
void decode (const vector < string* >&);
bool extractCode (const string& str, map<char,int>&);
void printDecoded (const vector < string* >&, const map<char,int>&);

int main(void){

  string str;
  getline(cin, str);
  stringstream ss (str);
  int number_of_cases;
  ss >> number_of_cases;
  getline (cin, str); //reading the blank line
  
  
  for (int caseCounter = 0; caseCounter < number_of_cases; caseCounter ++)
    {
      vector < string* > vec;
      string * line = new string;
      getline (cin, *line);
      while (cin.good() && notBlank(line)){
	vec.push_back(line);
	
	line = new string;
	getline(cin, *line);
      }

      decode(vec);
      
      for (vector < string* >::iterator itr = vec.begin(); itr != vec.end(); itr++)
	delete *itr;
    }


  
  return 0;
}

bool notBlank(string * const str ){
  if ((*str).length() == 0)
    return false;
  
  for(string::const_iterator itr = (*str).begin(); itr != (*str).end(); itr++)
    {
      int val = static_cast<int> (*itr);
      if (val != 9 && val != 10 && val != 32)
	return true;
    }

  return false;
}

void decode (const vector < string* >& inputVec){

  map<char,int> strMap;

  bool isDecoded = false;
  for (vector <string* >::const_iterator itr = inputVec.begin(); !isDecoded && itr != inputVec.end(); itr++)
    if ((**itr).length() == 43)
      isDecoded = extractCode (**itr, strMap);
  
  if (!isDecoded)
    cout << "No solution." << endl;

  else 
    printDecoded (inputVec , strMap);

  cout << endl;

}

bool extractCode (const string& str, map<char,int>& strMap){
  strMap.clear();
  string reference ("the quick brown fox jumps over the lazy dog");
  
  bool result = true;
  for (string::const_iterator itrRef = reference.begin(), itrStr = str.begin(); result && itrRef != reference.end(); itrStr++, itrRef++){
    if (*itrStr == ' ' || *itrRef == ' ') {
      if (*itrRef != *itrStr)
	result = false;
      continue;
    }
      if (strMap.find(*itrStr) == strMap.end())
      strMap[*itrStr] = *itrRef;
      else if (strMap.find(*itrStr) -> second != *itrRef)
      result = false;
  }
    
  return result;
}

void printDecoded (const vector < string* >& inputVec, const map<char,int>& strMap){

  for (vector<string* >::const_iterator itr = inputVec.begin(); itr != inputVec.end(); itr++){

    string::iterator strItr , strEnd;
    for (strItr = (**itr).begin(), strEnd = (**itr).end(); strItr != strEnd; strItr++)
      cout << (*strItr == ' ' ? ' ' : static_cast<char> (strMap.find(*strItr) -> second));

    cout << endl;
  }

  return;
}
