#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

void analyzeVotes(string* candidateNames, int numberOfCandidates , const vector<int*> &);

int main (void){
  string inStr;
  istringstream inSS;

  getline(cin , inStr);
  inSS.str(inStr);
  
  int numberOfCases;
  inSS >> numberOfCases;
  
  if (!inSS.fail())
    {
      // reading a blank line from input
      getline(cin , inStr);
     

      for (int counter = 0 ; counter < numberOfCases ; counter++){
      getline(cin , inStr);
      inSS.clear();
      inSS.str(inStr);
      
      int numberOfCandidates;
      inSS >> numberOfCandidates;

      string* candidateNames = new string[numberOfCandidates];
      
      for (int candCounter = 0 ; candCounter < numberOfCandidates ; candCounter ++){
       getline(cin ,candidateNames[candCounter]);

      }
      
      vector<int*>* ballotsPtr = new vector<int*>;
      vector<int*> ballots = *ballotsPtr;

      // reading the ballots
      getline (cin, inStr);
      while (!inStr.empty()){

	inSS.clear();
	inSS.str(inStr);
	int* currentVote = new int[numberOfCandidates];

	for (int candCounter = 0; candCounter < numberOfCandidates; candCounter++)
	  inSS >> currentVote[candCounter];
	
	(ballots).push_back(currentVote);
	
	getline(cin, inStr);
      }
      
      analyzeVotes(candidateNames , numberOfCandidates , ballots);

      delete[] candidateNames;
      
      vector<int*>::iterator itr;
      for (itr = (ballots).begin() ; itr != (ballots).end()  ; itr++)
	delete [] (*itr);

      delete ballotsPtr;
      
      }
      
    }
  
  else 
    cout << "Failed in specifying the number of cases" << endl;
  return 0;
}


void analyzeVotes(string* candidateNames , int numberOfCandidates , const vector<int*>& ballots){
  vector<int*>::const_iterator itr = (ballots).begin();
  for (;itr != (ballots).end() ; itr++){
        for (int counter = 0 ; counter < numberOfCandidates ; counter++)
	  cout << candidateNames[(*itr)[counter]-1] << " ";
	  //	  cout << (*itr)[counter] << " ";
    
    cout << endl;
  }
}
