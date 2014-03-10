#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int ways(unsigned int);

int w[30001];

int main(void){

  for (int counter = 0; counter < 30001; counter++)
    w[counter] = -1;
  
  unsigned int val;
  
  while (cin >> val){
    int waysCount = ways(val);
    if (waysCount > 1)
      cout << "There are " << waysCount << " ways";
    else
      cout << "There is only 1 way";
    cout << " to produce " << val << " cents change." << endl;
  }

  return 0;
}

/* This is wrong, as it allows for symmetry */
int ways(unsigned int val){
  if (w[val] >= 0)
    return w[val];

  int waysCount = 0;
  if (val > 50)
    waysCount += ways(val - 50) + 1;
  if (val > 25)
    waysCount += ways(val - 25) + 1;
  if (val > 10)
    waysCount += ways(val - 10) + 1;
  if (val > 5)
    waysCount += ways(val - 5) + 1;
  if (val > 1)
    waysCount += ways(val - 1) + 1;
  
  w[val] = waysCount;
  return waysCount;
}
