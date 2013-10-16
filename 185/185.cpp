#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <map>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::set;
using std::pair;
using std::map;
using std::max;

struct Letter {
  char name;
  vector<unsigned int> values;
};

typedef pair<char, unsigned int> FixedLetter;

/* global variables */
int number_of_variables;
set<char> varSet;
vector<map<char,unsigned int> > solutions;

bool propagate (const string& first , const string& second, const string& third, const map<char, unsigned int>& partial, vector<Letter>& remaining);
void search(const string& first, const string& second, const string& third, map<char, unsigned int>& partial, vector<Letter> remaining);
int varCount(const string& first, const string& second, const string& third, string& variables);

int main(void){
  return 0;
}

/* create a set and a string of names of variables and return the count of them */
int varCount(const string& first, const string& second, const string& third, string& variables, set<char>& vars){
  vars.clear();
  vars.insert(first.begin(), first.end());
  vars.insert(second.begin(), second.end());
  vars.insert(third.begin(), third.end());

  variables.clear();
  variables.insert(variables.end(), vars.begin(), vars.end());

  return vars.size();
}

void search(const string& first, const string& second, const string& third, map<char, unsigned int>& partial, vector<Letter> remaining)
{
  if (!propagate (first, second, third, partial, remaining))
    return;

  if (remaining.empty())
    solutions.push_back(partial);

  else
    {
      /* sort the values for the next assignment and continue the search */
      Letter currentLetter = remaining.back();
      remaining.pop_back();
      for (auto itr = currentLetter.values.begin(), endItr = currentLetter.values.end(); itr != endItr; itr++ )
	{
	  pair<char, unsigned int> assigned (currentLetter.name, *itr);
	  partial.insert(assigned);
	  search (first, second, third, partial, remaining);
	  partial.erase(currentLetter.name);
	}
    }
    
}


/* returns false if the domain of a variable becomes empty */
bool propagate (const string& first , const string& second, const string& third, const map<char, unsigned int>& partial, vector<Letter>& remaining){
  if (partial.size() == number_of_variables){
    // check whether all varialbes are assigned
    auto partialItr= partial.begin(), partialEndItr = partial.end();
    auto varSetItr = varSet.begin(), varSetEndItr = varSet.end();
    for (; partialItr != partialEndItr; partialItr++, varSetItr++)
      if (partialItr->first != *varSetItr)
	{
	  cout << "I have received a strange final solution" << endl;
	  exit (EXIT_FAILURE);
	}
    
    bool valid = true;
    vector<unsigned int> aux (max(first.size(), second.size()), 0);
    auto firstItr = first.rbegin(), secondItr = second.rbegin(), thirdItr = third.rbegin();
    auto auxItr = aux.begin();
    while (true){
      int firstVal = 0, secondVal = 0, thirdVal = 0;
      if (firstItr != first.rend()){
	firstVal = (partial.find(*firstItr))->second;
	firstItr++;
      }
      if (secondItr != second.rend()){
	secondVal = (partial.find(*secondItr))->second;
	secondItr++;
      }
      if (thirdItr != third.rend()){
	thirdVal = (partial.find(*thirdItr))->second;
	thirdItr++;
      }
      else 
	break;
      int auxVal = *(auxItr++);

      if (! (firstVal + secondVal + auxVal == thirdVal))
	{
	  if ((firstVal + secondVal + auxVal) % 10 == thirdVal)
	    {
	      int nextAuxVal = (firstVal + secondVal + auxVal) / 10;
	      *auxItr = nextAuxVal;
	    }
	  else 
	    return false;
	}
      
      
    }
    
  }
  
  return false;
  /* no pruning for now! Simply check the last result */
}
