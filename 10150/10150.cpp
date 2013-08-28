#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stringstream;
using std::vector;
using std::map;
using std::pair;

void printPath(const vector<vector<int> >&, const vector<string>&, int, int);
void createGraph(const vector<string>&, vector<vector<int> >&);
bool areDoublet(const string&, const string&);

int main(void){
  map<string,int> wordMap;
  vector<string> dict;
  string line;

  getline(cin, line);
  int counter = 0;
  while(!line.empty()){
    dict.push_back(line);
    wordMap.insert(pair<string,int> (line, counter++));
    getline(cin, line);
  }
  
  vector<vector<int> > dictGraph;
  createGraph(dict, dictGraph);

  while (getline(cin, line)){
    stringstream ss (line);
    string w1, w2;
    ss >> w1 >> w2;

    int index1 , index2;
    index1 = wordMap.find(w1) -> second;
    index2 = wordMap.find(w2) -> second;
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
  for (vector<string>::const_iterator itr1 = dict.begin(), itr1End = dict.end(); itr1 != itr1End; itr1++){
    int counter2 = 0;
    for (vector<string>::const_iterator itr2 = itr1 + 1, itr2End = dict.end(); itr2 != itr2End; itr2++)
      if (areDoublet(*itr1,*itr2))
	{
	  dictGraph[counter1].push_back(counter2);
	  dictGraph[counter2].push_back(counter2);
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
}

bool areDoublet(const string& first , const string& second){ 
  if (first.empty() || second.empty() || first.size() != second.size())
    return false;
  
  bool different = false;
  for (string::const_iterator itr1 = first.begin(), itr1End = first.end(), itr2 = second.begin(); itr1 != itr1End; itr1++, itr2++)
    if (*itr1 != *itr2)
      if (!different)
	return false;
      else
	different = true;
  
  return different;
}
