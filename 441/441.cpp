#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main(void) {
  int k;
  cin >> k;
  bool first = true;
  while (k){
    if (first)
      first = false;
    else
      cout << endl;
    vector<int> s(k);
    for (int counter = 0; counter < k; counter++)
      cin >> s[counter];
    for (int c1 = 0; c1 <= k-6; c1++)
      for (int c2 = c1+1; c2 <= k-5; c2++)
	for (int c3 = c2+1; c3 <= k-4; c3++)
	  for (int c4 = c3+1; c4 <= k-3; c4++)
	    for (int c5 = c4+1; c5 <= k-2; c5++)
	      for (int c6 = c5+1; c6 <= k-1; c6++)
		cout << s[c1] << " " 
		     << s[c2] << " "
		     << s[c3] << " "
		     << s[c4] << " "
		     << s[c5] << " "
		     << s[c6] << endl;
    cin >> k;
  }
  return 0;
}
