#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main(void) {
  int num;
  cin >> num;
  while (num) {
    vector<int> seq(num);
    for (int cnt=0; cnt<num; cnt++)
      cin >> seq[cnt];
    vector<int> nonz;
    bool any=false;
    for (int cnt=0; cnt<num; cnt++)
      if (seq[cnt]) {
	if (any)
	  cout << " ";
	cout << seq[cnt];
	any = true;
      }
    if (!any)
      cout << 0;
    cout << endl;
    cin >> num;
  }
  return 0;
}
