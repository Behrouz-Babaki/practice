#include <iostream>
#include <vector>
	
using std::cin;
using std::cout;
using std::endl;
using std::vector;

void checkMatrix(const vector<vector<int> >&);

int main(void){
  int n = -1;
  int currentNum = -1;
  cin >> n;
  while (n){
    vector<vector<int> > matrix(n, vector<int>(n,0));
    for (int lineCounter = 0; lineCounter < n; lineCounter++)
      for (int numCounter = 0; numCounter < n; numCounter++) {
	cin >> currentNum;
	matrix[lineCounter][numCounter] = currentNum;
	}

    checkMatrix(matrix);
    cin >> n;
  }


  return 0;
}

void checkMatrix(const vector<vector<int> >& matrix){
  int size = matrix.size();
  vector<int> oddRows;
  vector<int> oddCols;

  for (int row = 0; row < size; row++)
    {
      int sum = 0;
      for (int col = 0; col < size; col++)
	sum += matrix[row][col];
      if (sum % 2)
	oddRows.push_back(row);
    }

  for (int col = 0; col < size; col++)
    {
      int sum = 0;
      for (int row = 0; row < size; row++)
	sum += matrix[row][col];
      if (sum % 2)
	oddCols.push_back(col);
    }

  if (oddRows.empty() && oddCols.empty()){
    cout << "OK" << endl;
    return;
  }

  if (oddRows.size() == 1 && oddCols.size() == 1){
    cout << "Change bit (" << oddRows.front() + 1 << "," << oddCols.front() + 1 << ")" << endl;
    return;
  }

  cout << "Corrupt" << endl;
  return;
}
