#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::setw;
using std::left;
using std::right;

int main(void) {

  int testCounter = 0;
  int numNeighbours;
  while (cin >> numNeighbours)
    {
      testCounter++;
      vector<vector<int> > graph(20, vector<int>(20,-1));

      for (int counter=0; counter<20; counter++)
	graph[counter][counter] = 0;

      int nextNeighbour;
      for (int nCounter = 0; nCounter < numNeighbours; nCounter++){
	cin >> nextNeighbour;
	graph[0][nextNeighbour-1] = 1;
	graph[nextNeighbour-1][0] = 1;
      }

      for (int counter=1; counter < 19; counter++){
	cin >> numNeighbours;
	for (int nCounter = 0; nCounter < numNeighbours; nCounter++){
	  cin >> nextNeighbour;
	  graph[counter][nextNeighbour-1] = 1;
	  graph[nextNeighbour-1][counter] = 1;
	}
      }

      vector<vector<int> > distances(graph);

      for (int k = 0; k < 20; k++)
	for (int i = 0; i < 20; i++)
	  for (int j = 0; j < 20; j++)
	    {
	      if (distances[i][k] >=0 && distances[k][j] >= 0 && (distances[i][j] == -1 || distances[i][j] > distances[i][k] + distances[k][j])){
		distances[i][j] = distances[i][k] + distances[k][j];
		distances[j][i] = distances[i][j];
	      }
	    }

      cout << "Test Set #" << testCounter << endl;  
      int numCases;
      cin >> numCases;

	int first, second;
	for (int counter=0; counter<numCases; counter++){
	  cin >> first >> second;
	  cout << setw(2) << right << first << " to " << setw(2) << right << second << ": " << left << distances[first-1][second-1] << endl;
	}
	cout << endl;

    }    
  return 0;
}
