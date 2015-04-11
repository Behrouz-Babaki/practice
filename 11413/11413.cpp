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
    for (int i=0; i<num_v; i++)
      cin >> vessels[i];

  }
}

bool can(int capacity, int num_c){
  bool finish=false;
  int sum = 0, cnt=1;
  for(vector<int>::iterator itr=vessels.begin(),end=vessels.end();
      cnt <= num_c && itr!=end; itr++)
    if(sum+*itr>capacity) {
      cnt++;
      sum=*itr;
    }
    else
      sum += *itr;
  return (cnt <= num_c);
}
