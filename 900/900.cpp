#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main(void){
  vector<unsigned int> v(51);
  v[0] = 1;
  v[1] = 1;
  for (int counter = 2; counter <= 50; counter++)
    v[counter] = v[counter-1] + v[counter-2];

  int n;
  cin >> n;
  while (n != 0){
    cout << v[n] << endl;
    cin >> n;
  }
  
  return 0;
}
