#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int computeSum (const vector<vector<short> >&, size_t, size_t, size_t, size_t);

int main (void){
  size_t num;
  cin >> num;

  vector<vector<short> > vec (num, vector<short>(num, 0));
  for (size_t outer = 0; outer < num; outer++)
    for (size_t inner = 0; inner < num; inner ++)
      cin >> vec[outer][inner];

  int max = vec[0][0];
  int blockVal = max;

  for (size_t i1 = 0; i1 < num; i1++)
    for (size_t j1 = 0; j1 < num; j1++)
      for (size_t i2 = i1; i2 < num; i2++)
        for (size_t j2 = j1; j2 < num; j2++){
          blockVal = computeSum(vec, i1, j1, i2, j2);
          if (blockVal > max)
            max = blockVal;
        }

  cout << max << endl;
          

  // for (size_t outer = 0; outer < num; outer++){
  //   for (size_t inner = 0; inner < num; inner ++)
  //     cout << vec[outer][inner] << "\t";
  //   cout << endl;
  // }
  
  return 0;
}


int computeSum (const vector<vector<short> >& vec, size_t i1, size_t j1, size_t i2, size_t j2){
  int sum = 0;
  for (size_t row = i1; row <= i2; row++)
    for (size_t col = j1; col <= j2; col++)
      sum += vec[row][col];
  return sum;
}
