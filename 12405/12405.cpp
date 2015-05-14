#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::ws;
using std::vector;

int main(void) {
  int num_cases;
  cin >> num_cases;
  for (int case_cnt=0; case_cnt<num_cases; case_cnt++)  {
    int length;
    cin >> length >> ws;
    vector<bool> field(length);
    char ch;
    for (int cnt=0; cnt<length; cnt++){
      cin >> ch;
      field[cnt] = (ch=='.');
    }
    cin >> ws;

    int n=0, cnt=0;
    while(cnt<length)
      if (field[cnt]){
	n++;
	cnt+=3;
      }
      else
	cnt++;
    cout << "Case " << case_cnt+1 << ": " << n << endl;
  }
}
