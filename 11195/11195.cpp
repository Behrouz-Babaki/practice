#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::ws;

vector<vector<bool> > valid;
int num_sols;
int n;

void search(vector<int>&prev, int row, int mask);
bool is_attacked(int r1, int c1, int r2, int c2);

int main(void) {
  int case_num = 1;
  cin >> n >> ws;
  while (n) {
    num_sols=0;
    valid.clear();
    valid.resize(n, vector<bool>(n,true));
    char ch;
    for (int i=0; i<n; i++) {
      for(int j=0; j<n; j++) {
	cin >> ch;
	if (ch == '*')
	  valid[i][j]=false;
      }
      cin >> ws;
    }
    vector<int> prev;
    int mask = (1<<n);
    mask--;
    search(prev, 0, mask);
    cout << "Case " << case_num++ << ": " << num_sols << endl;
    cin >> n >> ws;
  }
  return 0;
}

void search(vector<int>&prev, int row, int mask) {
  if(row==n){
    num_sols++;
    return;
  }
  for (int i=0; i<n; i++){
    if (!(mask&(1<<i)) || !valid[row][i]) 
      continue;
    bool attacked=false;
    for(int j=0; !attacked && j<prev.size(); j++) 
      if (abs(row-j)==abs(i-prev[j]))
	attacked=true;
    if (!attacked){
      prev.push_back(i);
      mask &= ~(1<<i);
      search(prev, row+1, mask);
      prev.pop_back();
      mask |= (1<<i);
    }
  }
}

bool is_attacked(int r1, int c1,
		 int r2, int c2){
  if (abs(r1-r2)==abs(c1-c2))
    return true;
  return false;
}
