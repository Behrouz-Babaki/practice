#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::sort;


int main(void) {
  int n, d, r;
  cin >> n >> d >> r;
  while (n || d || r) {
    vector<int> morning(n), evening(n);

    for (int i = 0; i < n; i++) 
      cin >> morning[i];
    sort(morning.begin(), morning.end());

    for (int i = 0; i < n; i++) 
      cin >> evening[i];
    sort(evening.begin(), evening.end());

    int penalty = 0;
    for (int i=0; i <n; i++)
      if (morning[i]+evening[n-1-i] > d)
	penalty += (morning[i]+evening[n-1-i]-d)*r;

    cout << penalty << endl;
    cin >> n >> d >> r;
  }

  return 0;
}
