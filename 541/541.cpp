#include <iostream>
#include <vector>
	
using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main(void){
  int n = -1;
  int currentNum = -1;
  cin >> n;
  while (n){

    vector<int> colSum (n, 0);
    vector<int> rowSum (n, 0);


    for (int lineCounter = 0; lineCounter < n; lineCounter++)
      for (int numCounter = 0; numCounter < n; numCounter++) {
	cin >> currentNum;
	rowSum[lineCounter] += currentNum;
	colSum[numCounter] += currentNum;
      }
    
    bool tooMany = false;
    int oddRow = -1;
    int oddColumn = -1;
    for (int counter = 0; !tooMany && counter < n; counter++){
      if (rowSum[counter] % 2){
	if (oddRow == -1)
	  oddRow = counter;
	else
	  tooMany = true;
      }

      if (colSum[counter] % 2){
	if (oddColumn == -1)
	  oddColumn = counter;
	else
	  tooMany = true;
      }
    }
    
    if (oddRow == -1 && oddColumn == -1)
      cout << "OK" << endl;
    else if (tooMany)
      cout << "Corrupt" << endl;
    else
      cout << "Change bit (" << oddRow + 1 << "," << oddColumn + 1 << ")" << endl;

    cin >> n;
  }


  return 0;
}

