#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <queue>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stringstream;
using std::vector;
using std::map;
using std::pair;
using std::queue;

void printPath(const vector<vector<int> >&, const vector<string>&, int, int);
void createGraph(const vector<string>&, vector<vector<int> >&);
bool areDoublet(const string&, const string&);

int main(void)
{
  map<string,int> wordMap;
  vector<string> dict;
  string line;

  getline(cin, line);
  int counter = 0;
  while(!line.empty())
    {
      dict.push_back(line);
      if (wordMap.find(line) == wordMap.end())
	wordMap.insert(pair<string,int> (line, counter++));
      getline(cin, line);
    }
  
  vector<vector<int> > dictGraph;
  createGraph(dict, dictGraph);
  
  bool first = true;
  // TODO guard this against bad input
  while (getline(cin, line)){
    stringstream ss (line);
    string w1, w2;
    ss >> w1 >> w2;

    int index1 , index2;
    index1 = wordMap.find(w1) -> second;
    index2 = wordMap.find(w2) -> second;

    if (!first)
      cout << endl;
    else
      first = false;

    printPath(dictGraph, dict, index1, index2);

  }
  
  return 0;
}
/** 
 * Creates a graph from a set of words. Each two words which only differ in one letter will be connected in this graph. 
 * 
 * @param dict the set of words for which the graph will be created
 * @param dictGraph the output graph
 */
void createGraph(const vector<string>& dict, vector<vector<int> >& dictGraph){
  dictGraph.clear();
  dictGraph.resize(dict.size());
  
  int counter1 = 0;
  for (vector<string>::const_iterator itr1 = dict.begin(), itr1End = dict.end(); itr1 != itr1End; itr1++, counter1++){
    int counter2 = counter1 + 1;
    for (vector<string>::const_iterator itr2 = itr1 + 1, itr2End = dict.end(); itr2 != itr2End; itr2++, counter2++)
      if (areDoublet(*itr1,*itr2))
	{
	  dictGraph[counter1].push_back(counter2);
	  dictGraph[counter2].push_back(counter1);
	}
  }
  return;
}

/** 
 * Prints all the intermediate words to reach from one word to another, changing only one letter at each step of the path.
 * 
 * @param dictGraph  the graph showing the connectivity of words. Each two words which differ by only one letter are connected in this graph.
 * @param dict the list of words 
 * @param w1 index of the first word
 * @param w2 index of the second word
 */
void printPath(const vector<vector<int> >& dictGraph, const vector<string>& dict, int w1, int w2){
  if (w1 == w2 || dict[w1].length() != dict[w2].length())
    {
      cout << "No solution." << endl;
      return;
    }
    
  vector<int> parents(dict.size(), -1);
  queue<int> nodes;
  nodes.push(w1);

  bool found = false;

  while (!nodes.empty() && !found)
    {
      int current = nodes.front();
      nodes.pop();
      
      for (vector<int>::const_iterator itr = dictGraph[current].begin(), endItr = dictGraph[current].end(); !found && itr != endItr; itr++)
	if (parents[*itr] == -1)
	  {
	    parents[*itr] = current;
	    nodes.push(*itr);
	    if (*itr == w2)
	      found = true;
	  }
    }
 
  if (found){
    vector<string> chain;
    int next = w2;
    while (next != w1){
      chain.push_back(dict[next]);
      next = parents[next];
    }
    chain.push_back(dict[w1]);

    for (vector<string>::reverse_iterator itr = chain.rbegin() , endItr = chain.rend(); itr != endItr; itr++)
      cout << *itr << endl;
  }
  else 
    cout << "No solution." << endl;
  
  return;
}

/** 
 * Determines whether or not two strings differ in only one character
 * 
 * @param first the first word
 * @param second the second word
 * 
 * @return 
 */
bool areDoublet(const string& first , const string& second){ 
  if (first.empty() || second.empty() || first.length() != second.length())
    return false;
  
  bool different = false;
  for (string::const_iterator itr1 = first.begin(), itr1End = first.end(), itr2 = second.begin(); itr1 != itr1End; itr1++, itr2++)
    if (*itr1 != *itr2)
      if (different)
	return false;
      else
	different = true;
  
  return different;
}
