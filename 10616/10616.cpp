#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::sort;
using std::map;

int get_sum(int id, int M, int D, int sum);
class triplet {
public:
  triplet(int a, int b, int c, int d) 
    : _a(a) , _b(b), _c(c), _d(d) {}
  bool operator<(const triplet& rhs) const {
    if (rhs._a != _a)
      return (rhs._a < _a);
    if (rhs._b != _b)
      return (rhs._b < _b);
    if (rhs._c != _c)
      return (rhs._c < _c);
    return (rhs._d < _d);
  }
  int _a, _b, _c, _d;
};

map<triplet, int> total_map;
vector<int> numbers;
vector<int> totals;
int N, Q;

int main(void) {
  cin >> N >> Q;
  int set_cnt = 0;
  while (N && Q) {
    total_map.clear();
    numbers.clear();
    numbers.resize(N);
    totals.clear();
    totals.resize(N);
    for (int num_cnt = 0; num_cnt < N; num_cnt++)
      cin >> numbers[num_cnt];
    sort(numbers.rbegin(), numbers.rend());

    totals[0] = numbers[0];
    for (int num_cnt = 1; num_cnt < N; num_cnt++)
      totals[num_cnt] = numbers[num_cnt] + totals[num_cnt-1];

    cout << "SET " << ++set_cnt << ":" << endl;
    int D, M;
    for (int q_cnt = 0; q_cnt < Q; q_cnt++) {
      cin >> D >> M;
      cout << "QUERY " << q_cnt+1 << ": " << get_sum(0, M, D, 0) << endl;
    }
    cin >> N >> Q;
  }
  return 0;
}

int get_sum(int id, int M, int D, int res) {
  if (M > (N - id))
    return 0;
  if (M == 0 && res == 0)
    return 1;
  if (id == N)
    return 0;
  // if (M == 1 && res == (numbers[id]%D))
  //   return 1;
  triplet t(id, M, D, res);
  if (total_map.find(t) != total_map.end())
    return total_map[t];
  int count;
  int res2;
  if (res >= (numbers[id]%D))
    res2 = res - (numbers[id]%D);
  else
    res2 = res - (numbers[id]%D) + D;
  count = get_sum(id+1, M, D, res) + 
    get_sum(id+1, M-1, D, res2);
  total_map[t] = count;
  return count;
}
