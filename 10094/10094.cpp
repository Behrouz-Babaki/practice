#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main(void) {
  int num;
  while (cin >> num) {
    if (num==2||num==3) {
      cout << "Impossible" << endl;
      continue;
    }
    vector<int> sol(num);
    vector<int> oddlist((num+1)/2), evenlist(num/2);
    int id=0;
    for(int i=2;i<=num; i+=2)
      evenlist[id++] = i;
    id=0;
    for(int i=1;i<=num; i+=2) 
      oddlist[id++] = i;
    if (num%6==2) {
      oddlist.erase(oddlist.begin()+2);
      oddlist.push_back(5);
      oddlist[0]=3;
      oddlist[1]=1;
    }
    if(num%6==3) {
      evenlist.erase(evenlist.begin());
      evenlist.push_back(2);
      oddlist.erase(oddlist.begin());
      oddlist.erase(oddlist.begin());
      oddlist.push_back(1);
      oddlist.push_back(3);
    }
    id=0;
    for(auto i : evenlist)
      sol[id++] = i;
    for(auto i : oddlist)			
      sol[id++] = i;
    
    cout << sol[0];
    for (int i=1; i<num; i++)
      cout << " " << sol[i];
    cout << endl;
  }
    return 0;
}

