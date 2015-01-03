#include <iostream>
using std::cout;
using std::cin;
using std::endl;

const unsigned int maxChange = 30000;
long long int w[maxChange+1][5];
unsigned int coins[] = {50, 25, 10, 5, 1};
const unsigned int coinTypesCount = 5;

int main(void){
  
  /* There is only 1 way to generate 0 using any types of coins */
  for (unsigned int coinCounter = 0; coinCounter < coinTypesCount; coinCounter++)
    w[0][coinCounter] = 1;
  
  /* For every value of change, compute the number of ways that this
     value could be generated using coins no larger than a limit. Store
     this count in w[value][limit]. */
  for (unsigned int counter = 1; counter < maxChange + 1; counter++)
    for (unsigned int coinCounter = 0; coinCounter < coinTypesCount; coinCounter++){
      w[counter][coinCounter] = 0;
      for (unsigned int innerCounter = coinCounter; innerCounter < coinTypesCount; innerCounter++)
	if (counter >= coins[innerCounter])
	  w[counter][coinCounter] += w[counter-coins[innerCounter]][innerCounter];
    }

  unsigned int val;
  
  while (cin >> val){
    if (w[val][0] > 1)
      cout << "There are " << w[val][0] << " ways";
    else
      cout << "There is only 1 way";
    cout << " to produce " << val << " cents change." << endl;
  }

  return 0;
}


