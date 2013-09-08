#include <iostream>
#include <set>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>

using std::cin;
using std::cout;
using std::endl;
using std::set;
using std::vector;
using std::min;
using std::set_intersection;
using std::set;

void printStats(int);
bool noCommonFactor (int, int, int);
void findFactors (int, vector<int>&);


int main(void){
  int n;
  cin >> n;
  while(cin){
    printStats(n);
    cin >> n;
  }
  return 0;
}     

void printStats(int n){
  
  int tripleCount = 0;
  set<int> partOfSolution;

  for (int x = 1; x <= n/sqrt(2) + 1; x++)
    {
      int y = x+1;
      int z = sqrt((x*x) + (y*y));
      while (z <= n)
	{
	  if((x*x + y*y) == z*z)
	    {
	      partOfSolution.insert(x);
	      partOfSolution.insert(y);
	      partOfSolution.insert(z);
		
	      if (noCommonFactor(x,y,z))
		tripleCount ++;
	    }

	  y++;
	  z = sqrt ((x*x) + (y*y));
	}
    }
    
  /** calculating the count of numbers which are not part of any triple   */
  int prev = 0;
  int notPartOfSolution = 0;
  for (set<int>::iterator itr = partOfSolution.begin() , endItr = partOfSolution.end(); itr != endItr; itr++){
    notPartOfSolution += (*itr - prev - 1);
    prev = *itr;
  }
      
      
  cout << tripleCount << " " << notPartOfSolution << endl;

}

bool noCommonFactor (int x, int y, int z){
  vector<int> x_factors, y_factors, z_factors;
  findFactors(x, x_factors);
  findFactors(y, y_factors);
  findFactors(z, z_factors);

  vector<int> xy_intersection (min(x_factors.size(), y_factors.size()));
  vector<int>::iterator xy_itr = set_intersection (x_factors.begin(), x_factors.end(), y_factors.begin(), y_factors.end(), xy_intersection.begin());
  xy_intersection.resize(xy_itr - xy_intersection.begin());
  
  vector<int> xyz_intersection  (min(z_factors.size(), xy_intersection.size()));
  vector<int>::iterator xyz_itr = set_intersection (xy_intersection.begin(), xy_intersection.end(), z_factors.begin(), z_factors.end(), xyz_intersection.begin());
  xyz_intersection.resize(xyz_itr - xyz_intersection.begin());

  return (xyz_intersection.size() == 0);
    
}

void findFactors (int x, vector<int>& x_factors){
  for (int i = 2; i <= x; i++)
    if ( x % i == 0) {
      x_factors.push_back(i);
      while ( x % i == 0)
	x /= i;
    }
}
