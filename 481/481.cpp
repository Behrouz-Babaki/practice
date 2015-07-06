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
  vector<int> sz(n);
  vector<int> next(n);
  sz[n-1] = 1;
  next[n-1] = -1;
  for (int i = n-2; i >= 0; i--) {
    int max_val = 0;
    int id = -1;
    for (int j = n-1; j > i; j--) 
      if (seq[j] > seq[i] && sz[j] > max_val) {
	max_val = sz[j];
	id = j;
      }
    sz[i] = max_val + 1;
    next[i] = id;
  }
  
  int max_id = n-1;
  int max_val = 1;
  for (int i = n-2; i >=0; i--)
    if (sz[i] > max_val) {
      max_id = i;
      max_val = sz[i];
    }
  
  cout << max_val << endl;
  cout << "-" << endl;
  int id = max_id;
  while (id >= 0) {
    cout << seq[id] << endl;;
    id = next[id];
  }
  return 0;
}
