#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

vector<int> vessels;
bool can(int capacity, int num_c);

int main(void) {
  int num_v, num_c;
  while (cin >> num_v >> num_c) {
    vessels.clear();
    vessels.resize(num_v);
    int sum=0;
    for (int i=0; i<num_v; i++){
      cin >> vessels[i];
      sum+=vessels[i];
    }
    int hi=sum, lo=0, mid;
    while (hi>lo+1){
      mid=(hi+lo)/2;
      if(can(mid, num_c))
	hi=mid;
      else
	lo=mid;
    }
    cout << hi << endl;
  }
}

bool can(int capacity, int num_c){
  bool fail=false;
  int sum = 0, cnt=1;
  for(vector<int>::iterator itr=vessels.begin(),end=vessels.end();
      !fail && itr!=end; itr++)
    if (*itr>capacity)
      fail=true;
    else if(sum+*itr>capacity) {
      cnt++;
      if (cnt>num_c)
	fail=true;
      sum=*itr;
    }
    else
      sum += *itr;
  
  return !fail;
}
