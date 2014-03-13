#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main (void){
  size_t num;
  cin >> num;

  vector<vector<short> > vec (num, vector<short>(num, 0));
  for (size_t outer = 0; outer < num; outer++)
    for (size_t inner = 0; inner < num; inner ++)
      cin >> vec[outer][inner];

  for (size_t outer = 0; outer < num; outer++){
    for (size_t inner = 0; inner < num; inner ++)
      cout << vec[outer][inner] << "\t";
    cout << endl;
  }
  
  return 0;
}
