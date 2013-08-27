#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
using namespace std;

void analyzeVotes(string* candidateNames, int numberOfCandidates , const vector<int*> &);
void decide (const vector<int*>& ballots , set<int>& eliminated , bool& done , int &winner , int);

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

  set<int> eliminated;
  bool done = false;
  
  int winner = -1;
  while (!done)
    decide(ballots , eliminated , done , winner, numberOfCandidates);
  if (eliminated.size() != numberOfCandidates)
    cout << candidateNames[winner] << endl;
  else
    for (set<int>::iterator itr = eliminated.begin() ; itr != eliminated.end() ; itr++)
      cout << candidateNames[*itr] << endl;
    
}


void decide (const vector<int*>& ballots , set<int>& eliminated , bool &done , int &winner, int numberOfCandidates){
  int *stat = new int[numberOfCandidates];
  for (int counter = 0 ; counter < numberOfCandidates ; counter++)
    stat[counter] = 0;
  
  for (vector<int*>::const_iterator itr = ballots.begin() ; itr != ballots.end() ; itr++){
    int *current_vote = *itr;
    int counter;
    for (counter = 0 ; counter < numberOfCandidates && eliminated.find(current_vote[counter]) != eliminated.end() ; counter++);
    stat[counter] ++;
  }
  
  vector<int> losers;

  done = false;
  int max = -1;
  int min = stat[0];
  for (int counter = 0 ; counter < numberOfCandidates ; counter++)
    if (eliminated.find(counter) != eliminated.end()){
    if (stat[counter] > max){
      winner = counter;
      max = stat[counter];
    }
  
    if (stat[counter] == min)
      losers.push_back(counter);
    else if (stat[counter] < min){
      min = stat[counter];
      losers.clear();
      losers.push_back(counter);
    }
  }

  eliminated.insert(losers.begin() , losers.end());

  if (stat[winner] > ballots.size() /2)
    done = true;
  else if (numberOfCandidates ==  eliminated.size()){
    done = true;
    eliminated.clear();
    eliminated.insert(losers.begin() , losers.end());
  }
  else 
    done = false;
  
  delete[] stat;
}
