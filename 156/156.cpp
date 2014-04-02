#include <iostream>
#include <set>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::set;
using std::vector;

bool check(const string& first, const string& second);
void initVec(const string& str, vector<short>& vec);

int main(void){
  string word;
  set<string> ananas;
  set<string> theRest;
  cin >> word;
  while (!word.length() == 1 || word.front() != '#'){
    
    bool isAna = true;
    vector<set<string>::const_iterator> itrVec;
    set<string>::const_iterator ananas_itr = ananas.begin(), temp_itr;
    while(ananas_itr != ananas.end()){
      ananas_itr++;
      temp_itr = ananas_itr;
      ananas_itr--;
      if(check(*ananas_itr, word)){
        isAna = false;
        theRest.insert(*ananas_itr);
        ananas.erase(ananas_itr);
      }
      ananas_itr = temp_itr;
    }

    
    for(set<string>::const_iterator itr = theRest.begin(), endItr = theRest.end(); isAna && itr != endItr; itr++)
      if (check(*itr,word))
        isAna = false;

    if (isAna)
      ananas.insert(word);
    else
      theRest.insert(word);
                           
    cin >> word;
  }
  
  for (set<string>::const_iterator itr = ananas.begin(), endItr = ananas.end(); itr != endItr; itr++)
    cout << *itr << endl;

  return 0;
}

bool check(const string& first, const string& second){
  if (first.length() != second.length())
    return false;

  vector<short> firstVec;
  initVec(first,firstVec);

  vector<short> secondVec;
  initVec(second, secondVec);

  bool result = true;
  for (vector<short>::const_iterator itr1 = firstVec.begin(), itr2 = secondVec.begin(), endItr = firstVec.end();
       result && itr1!=endItr; itr1++, itr2++)
    if (*itr1 != *itr2)
      result = false;

  return result;
}

void initVec(const string &str, vector<short>& vec){
  vec.resize(str.length(), 0);
  for (string::const_iterator itr = str.begin(), endItr = str.end(); itr!=endItr; itr++){
    short ch = static_cast<short> (*itr);
  if(ch>97)
      vec[ch - 97]++;
  else
      vec[ch - 65]++;
  }
}
