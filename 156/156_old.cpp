#include <iostream>
#include <unordered_set>
#include <vector>
#include <set>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::unordered_set;
using std::vector;
using std::set;

void printSet(const unordered_set<string> &);
void perms(const string& original_string, vector<bool>& indicator, string& partial_string, vector<string>& all_perms);
bool checkWord(string word, const unordered_set<string>& wordSet, set<string>& anana);
bool theSame (const string& first, const string& second);
char lower(const char ch);

int main(void){
  string word;
  unordered_set <string> wordSet;
  set<string> anana;
  cin >> word;
  while (!word.length() == 1 || word.front() != '#'){


    if (checkWord(word, wordSet, anana))
      anana.insert(word);

    wordSet.insert(word);
    cin >> word;
  }
  
  for (set<string>::const_iterator itr = anana.begin(), endItr = anana.end(); itr != endItr; itr++)
    cout << *itr << endl;

  return 0;
}

void printSet(const unordered_set<string> & givenSet){
  for (unordered_set<string>::const_iterator itr = givenSet.begin(), endItr = givenSet.end(); itr != endItr; itr++)
    cout << *itr <<  " ";
  cout << endl;
}

void perms(const string& original_string, vector<bool>& indicator, string& partial_string, vector<string>& all_perms){
   bool finished = true;
   string::const_iterator strItr = original_string.begin();
   vector<bool>::iterator indItr = indicator.begin(), indEnd = indicator.end();
   for (;indItr != indEnd; indItr++, strItr++)
      if (*indItr){
         finished = false;
         partial_string.append(1,*strItr);
         *indItr = false;
         perms(original_string, indicator, partial_string, all_perms);
         partial_string.erase(partial_string.end()-1, partial_string.end());
         *indItr = true;
      }

   if (finished)
      all_perms.push_back(partial_string);
}

bool checkWord(string word, const unordered_set<string>& wordSet, set<string>& anana)
{
  vector<bool> indicator;
  for (string::const_iterator itr = word.begin(), endItr = word.end(); itr != endItr; itr++)
    indicator.push_back(true);
  vector<string> allPerms;
  string emptyStr;
  perms(word, indicator, emptyStr, allPerms);

  bool isAna = true;
  for (vector<string>::const_iterator itr1 = allPerms.begin(), endItr1 = allPerms.end(); isAna && itr1 != endItr1; itr1++){
    //search in anana
    for (set<string>::iterator itr = anana.begin(), endItr = anana.end(); isAna && itr != endItr; itr++)
      if (theSame (*itr1, *itr)){
        isAna = false;
        anana.erase(itr);
      }
    
    //search in all words
    for (unordered_set<string>::const_iterator itr = wordSet.begin(), endItr = wordSet.end(); isAna && itr != endItr; itr++)
      if (theSame (*itr1, *itr))
        isAna = false;

  }
  return isAna;
}

bool theSame (const string& first, const string& second){
  bool result = true;
  if (first.length() != second.length())
    return false;

  for (string::const_iterator itr1 = first.begin(), itr2 = second.begin(), end1 = first.end(); itr1 != end1; itr1++, itr2++)
    if (lower(*itr1) != lower(*itr2))
      return false;

  return true;
}


char lower(const char ch){
  if (ch >= 65 && ch <= 90)
    return ch + 32;

  return ch;
}
