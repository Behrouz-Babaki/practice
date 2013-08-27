#include <iostream>
#include <sstream>
#include <string>

using namespace std;


int main (void){
  
  int cases;
  cin >> cases;
  
  for (int counter = 0 ; counter < cases  ; counter++)
    {
      int farmers;
      double cost = 0;
      cin >> farmers;
      for (int farmercount = 0 ; farmercount < farmers ; farmercount ++){
	int size , animals , env;
	cin >> size >> animals >> env;
	cost += size * env;
      }
      
      cout <<  cost << endl;
	
    }

  return 0;
}

