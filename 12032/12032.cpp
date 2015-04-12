#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

vector<int> rungs;

bool can(int k);

int main(void) {
  int num_cases;
  cin >> num_cases;
  for(int case_cnt=1; case_cnt <= num_cases; case_cnt++) {
    cout << "Case " << case_cnt << ": ";
    int n;
    cin >> n;
    rungs.clear();
    rungs.resize(n);
    cin >> rungs[0];
    int max_diff = rungs[0];
    for(int i=1; i<n; i++){
      cin >> rungs[i];
      if (rungs[i]-rungs[i-1] > max_diff)
	max_diff = rungs[i]-rungs[i-1];
    }
    int lo=max_diff, hi=lo+n, mid;
    if (can(lo))
      cout << lo << endl;
    else {
      while (hi>lo+1) {
	mid=(hi+lo)/2;
	if(can(mid))
	  hi=mid;
	else
	  lo=mid;
      }
      cout << hi << endl;
    }
  }
  return 0;
}

bool can(int k) {
  bool fail = false;
  int n=rungs.size();
  if (k<rungs[0])
    return false;
  if(rungs[0]==k)
    k--;
  for (int i=1; !fail && i<n;i++)
    if(rungs[i]-rungs[i-1]>k)
      fail=true;
    else if(rungs[i]-rungs[i-1]==k)
      k--;
  return !fail;
}
