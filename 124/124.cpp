/**
 * @file   124.cpp
 * @author Behrouz Babaki
 * @date   Thu Feb 13 22:49:29 2014
 * 
 * @brief  UVA onlineJudge problem no. 124
 *
 * Given a list of variable constraints of the form x < y,
 * you are to write a program that prints all orderings of the
 * variables that are consistent with the constraints.
 */

#include <iostream>
#include <sstream>
#include <string>
#include <set>
#include <map>
#include <utility>
#include <cstdlib>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::istringstream;
using std::set;
using std::pair;
using std::make_pair;
using std::map;
using std::vector;

vector<short int> printed;      /**< variables printed so far */
map<char, int> charMap;
vector<char> charList;
vector<vector<bool> > arr;
string sequence;

void printSequence();
void findRoots(vector<int>&);

int main(void){

  string line;
  getline(cin, line);
  while (cin.good()){

    istringstream ss(line);
    charMap.clear();
    charList.clear();
    short int charIdx = 0;
    while (!ss.eof()){
      char ch;
      ss >> ch;
      if (!ss.fail() &&
        charMap.find(ch) == charMap.end()){
          charMap[ch] = charIdx++;
          charList.push_back(ch);
      }

    }

    size_t num_var = charMap.size();
    arr.clear();
    arr.resize(num_var, vector<bool> (num_var,false));

    getline(cin,line);
    if (!cin.good()){
      cout << "problem reading constraints" << endl;
      exit(EXIT_FAILURE);
    }

    istringstream ss2(line);
    set<pair<char,char> > pairSet;
    while (!ss2.eof()){
      char first, second;
      ss2 >> first >> second;
      if (!ss2.fail()){
        map<char,int>::iterator firstItr, secondItr;
        firstItr = charMap.find(first);
        secondItr = charMap.find(second);
        if (firstItr != charMap.end() && secondItr != charMap.end())
          arr[firstItr->second][secondItr->second] = true;
      }
      
      printSequence();
    }

  getline(cin, line);
  }

  return 0;
}

void printSequence(void){

  if (sequence.size() == charMap.size()){
    cout << sequence << endl;
    return;
  }

  vector<int> roots;
  findRoots(roots);
  for (vector<int>::iterator itr = roots.begin(), itr_end  = roots.end();
       itr != itr_end; itr++){
    printed.push_back(*itr);
    sequence.push_back(charList[*itr]);
    printSequence();
    printed.pop_back();
    sequence.erase(sequence.end()-1);
  }

}

void findRoots(vector<int>& roots){
  //TODO implement the method
}
