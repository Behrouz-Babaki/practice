#include <iostream>
#include <stack>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::stack;
using std::vector;

int main(void)  {
  unsigned int input;
  cin >> input;

  while (input) {

    vector<size_t> ind1, ind2;
    bool sw = true;
    for (size_t cnt = 0; cnt < 32; cnt++) {
      if ((input & (1 << cnt)) != 0) {
	if (sw)
	  ind1.push_back(cnt);
	else 
	  ind2.push_back(cnt);

	sw = !(sw);
      }
    }

  
    unsigned int first = 0, second = 0;
    
    for (auto num : ind1) 
      first |= (1 << num);

    for (auto num: ind2)
      second |= (1 << num);
    
    cout << first << " " << second << endl;
    cin >> input;
  }
  
  return 0;
}
