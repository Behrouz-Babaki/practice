#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::map;
using std::string;
using std::vector;
using std::make_pair;
using std::min;

int main(void) {
  int nCities;
  int nSegments;
  int caseCounter = 1;
  cin >> nCities >> nSegments;
  while (nCities || nSegments) {
    map<string,int> cities;
    vector<vector<unsigned int> > limits (nCities,vector<unsigned int>(nCities, 0));

    for (int counter = 0; counter < nSegments; counter++)
      {
	string firstCity, secondCity;
	int limit;
	cin >> firstCity >> secondCity >> limit;

	map<string,int>::iterator itr1, itr2;
	int id1, id2;

	itr1 = cities.find(firstCity);
	if (cities.find(firstCity) == cities.end()){
	  id1 = cities.size();
	  cities.insert(make_pair(firstCity, id1));
	}
	else
	  id1 = itr1->second;

	itr2 = cities.find(secondCity);
	if (cities.find(secondCity) == cities.end()){
	  id2 = cities.size();
	  cities.insert(make_pair(secondCity, id2));
	}
	else 
	  id2 = itr2->second;
	
	limits[id1][id2] = limit;
	limits[id2][id1] = limit;
      }

    vector<vector<unsigned int> > dists (limits);

    string source, dest;
    cin >> source >> dest;

    for (int k = 0; k < nCities; k++)
      for (int i = 0; i < nCities; i++)
	{
	  if (k != i)
	    for (int j = 0; j < nCities; j++)
	      {
		int dist = min(dists[i][k], dists[k][j]);
		if (i != j && dist > dists[i][j]){
		  dists[i][j] = dist;
		  dists[j][i] = dist;
		}
	      }
	}
    cout << "Scenario #" << caseCounter << endl;
    cout << dists[cities.at(source)][cities.at(dest)] << " tons" << endl;
    cout << endl;
    cin >> nCities >> nSegments;
    caseCounter++;
  }
  return 0;
}
