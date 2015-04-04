#include <iostream>
#include <string>
#include <utility>
#include <set>
#include <queue>
#include <vector>
#include <functional>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::pair;
using std::make_pair;
using std::set;
using std::priority_queue;
using std::vector;
using std::greater;

int main(void) {
  string kw;
  int id, period;
  set<pair<int, int> >queries;
  cin >> kw;
  while (kw != "#") {
    cin >> id >> period;
    queries.insert(make_pair(period, id));
    cin >> kw;
  }
  int k; 
  cin >> k;
  //priority_queue<pair<int,int> , vector<pair<int,int> >, greater<pair<int, int> > > top;
  priority_queue<pair<int,int> > results;
  int num = (k / queries.size()) + 1;
  for (auto q : queries) 
    for (int cnt = 1; cnt <= num; cnt++) {
      results.push(make_pair(-q.first*cnt, -q.second));
    }
  for (int cnt= 0; cnt < k; cnt++){
    cout << -results.top().second << endl;
    results.pop();
  }
  return 0;
}
