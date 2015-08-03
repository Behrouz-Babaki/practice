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

int get_sum(int id, int M, int sum);
class triplet {
public:
  triplet(int a, int b, int c) 
    : _a(a) , _b(b), _c(c) {}
  bool operator<(const triplet& rhs) const {
    if (rhs._a != _a)
      return (rhs._a < _a);
    if (rhs._b != _b)
      return (rhs._b < _b);
    return (rhs._c < _c);
  }
  int _a, _b, _c;
};

map<triplet, int> total_map;
vector<int> numbers;
int N, Q;

int main(void) {
  cin >> N >> Q;
  int set_cnt = 0;
  while (N && Q) {
    total_map.clear();
    numbers.clear();
    numbers.resize(N);
    vector<int> totals(N);
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
      int sol = 0;
      int mult = 1;
      while (D*mult <= totals[M-1]) {
	sol += get_sum(0, M, D*mult);
	mult++;
      }
      cout << "QUERY " << q_cnt+1 << ": " << sol << endl;
    }
    cin >> N >> Q;
  }
  return 0;
}

int get_sum(int id, int M, int sum) {
  if (id == N || M == 0 || sum <= 0)
    return 0;
  if (M == 1 && sum == numbers[id])
    return 1;
  triplet t(id, M, sum);
  if (total_map.find(t) != total_map.end())
    return total_map[t];
  int count;
  count = get_sum(id+1, M, sum) + 
    get_sum(id+1, M-1, sum-numbers[id]);
  total_map[t] = count;
  return count;
}
