#include <iostream>
#include <vector> 

using std::cin;
using std::endl;
using std::cout;
using std::vector;

int main(void) {
  vector<int> seq;
  int val;
  while (cin >> val)
    seq.push_back(val);
  int n = seq.size();
  vector<int> M(n+1), P(n, -1);
  int L = 0;
  
  for (int i=0; i<n; i++) {
    int k;
    //binary search k in seq[M[1]]..seq[M[L]]
    int lo = 1, hi = L, mid;
    while (lo <= hi) {
      mid = (lo + hi)/2;
      if (seq[M[mid]] < seq[i])
	lo = mid + 1;
      else 
	hi = mid - 1;
    }

    int newL = lo;
    P[i] = M[newL-1];
    M[newL] = i;

    if (newL > L)
      L = newL;
  }

  vector<int> res(L);
  int k = M[L];
  for (int i = L-1; i>=0; i--){
    res[i] = seq[k];
    k = P[k];
  }
  cout << L << "\n" << "-" << endl;
  for (auto i : res)
    cout << i << endl;
  return 0;
}
