#include <iostream>
#include <queue>
#include <functional>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::priority_queue;
using std::greater;
using std::vector;

int main(void) {
  size_t N;
  cin >> N;
  while (N > 0) {
    priority_queue<size_t, vector<size_t>, greater<size_t> > numbers;
    size_t current_num;
    for (size_t num_cnt = 0; num_cnt < N; num_cnt++)
      {
	cin >> current_num;
	numbers.push(current_num);
      }
    size_t sum;
    unsigned long long int cost;
    cost = 0;
    while (numbers.size() > 1){
      size_t num1 = numbers.top();
      numbers.pop();
      size_t num2 = numbers.top();
      numbers.pop();
      cost += (num1 + num2);
      numbers.push(num1+num2);
    }
    cout << cost << endl;
    cin >> N;
  }
  return 0;
}
