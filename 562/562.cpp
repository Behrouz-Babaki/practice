#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main(void){
  int noCases;
  cin >> noCases;
  for (int caseCounter=0; caseCounter < noCases; caseCounter++)
    {
      int noCoins;
      cin >> noCoins;
      vector<size_t> coins(noCoins);
      for (int counter=0; counter<noCoins; counter++){
	cin >> coins[counter];
      }
      
	
    } //cases
  return 0;
}
