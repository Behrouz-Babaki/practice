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
    int b = -1, e = -1, i=0;
    bool inzero=false;
    while (i<num){
      if (seq[i]==0 && !inzero)
	e = i;
      inzero = (seq[i]==0);
      if (b==-1 && seq[i]>0)
	b = i;
      i++;
    }
    if (e == -1)
      e = seq.size();
    if (b == -1)
      cout << 0;
    for (int i=b; i<e; i++) {
      if (i>b)
	cout << " ";
      cout << seq[i];
    }
    cout << endl;
    cin >> num;
  }
  return 0;
}
