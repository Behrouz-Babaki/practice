#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::sort;

int main(void){
  int n_heads, n_knights;
  cin >> n_heads >> n_knights;
  while (n_heads && n_knights) {
    vector<int> heads(n_heads);
    vector<int> knights(n_knights);
    for (int i=0; i<n_heads; i++)
      cin >> heads[i];
    for (int i=0; i<n_knights; i++)
      cin >> knights[i];
    sort(heads.begin(), heads.end());
    sort(knights.begin(), knights.end());
    int j=0, money=0;
    bool fail=false;
    for (int i=0; !fail && i<n_heads; i++) {
      while (j<n_knights && knights[j]<heads[i])
	j++;
      if(j==n_knights)
	fail=true;
      else {
	money+=knights[j];
	j++;
      }
    }
    if (fail)
      cout << "Loowater is doomed!" << endl;
    else
      cout << money << endl;
    cin >> n_heads >> n_knights;
  }
  return 0;
}
