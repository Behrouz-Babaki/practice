#include <iostream>
using std::cout;
using std::cin;
using std::endl;

long long int ways(unsigned int, unsigned int);

long long int w[30001][5];
int coins[] = {50, 25, 10, 5, 1};
const int coinTypes = 5;

int main(void){

  for (int counter = 0; counter < 30001; counter++)
    for (int coinCounter = 0; coinCounter < 5; coinCounter++)
      w[counter][coinCounter] = -1;
  
  unsigned int val;
  
  while (cin >> val){

    long long int waysCount = ways(val, 0);
    if (waysCount > 1)
      cout << "There are " << waysCount << " ways";
    else
      cout << "There is only 1 way";
    cout << " to produce " << val << " cents change." << endl;

  }

  return 0;
}


long long int ways(unsigned int val, unsigned int boundIndex){
  if (!val)
    return 1;

  if (w[val][boundIndex] >= 0)
    return w[val][boundIndex];

  long long int waysCount = 0;
  for (unsigned int boundIdCounter = boundIndex; boundIdCounter < coinTypes; boundIdCounter++)
    if (val >= coins[boundIdCounter])
      waysCount += ways(val - coins[boundIdCounter], boundIdCounter);
  
  w[val][boundIndex] = waysCount;
  return waysCount;
}

