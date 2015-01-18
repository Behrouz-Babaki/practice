#include <iostream>
#include <stack>
#include <queue>
#include <bitset>

using std::cin;
using std::cout;
using std::endl;
using std::stack;
using std::queue;
using std::priority_queue;
using std::bitset;

int main(void) {
  size_t num_operations;
  while (cin >> num_operations) {
    stack<size_t> s;
    queue<size_t> q;
    priority_queue<size_t> pq;
    bool is_stack = true, 
      is_queue = true,
      is_pqueue = true;
    for (size_t op_cnt = 0; op_cnt < num_operations; op_cnt++) {
      size_t op_num, value;
      cin >> op_num >> value;
      if (op_num == 1) {
	s.push(value);
	q.push(value);
	pq.push(value);
      }
      else { //op_num == 2
	if (s.empty()) 
	  is_stack = is_queue = is_pqueue = false;
	else{
	  if (is_stack && s.top() != value)
	    is_stack = false;
	  if (is_queue && q.front() != value)
	    is_queue = false;
	  if (is_pqueue && pq.top() != value)
	    is_pqueue = false;
	  s.pop();
	  q.pop();
	  pq.pop();
	}
      }
    }
    bitset<3> bs;
    bs[0] = is_stack;
    bs[1] = is_queue;
    bs[2] = is_pqueue;
    switch (bs.to_ulong()) {
    case 0:
      cout << "impossible";
      break;
    case 1:
      cout << "stack";
      break;
    case 2:
      cout << "queue";
      break;
    case 4:
      cout << "priority queue";
      break;
    default:
      cout << "not sure";
      break;
    }
    cout << endl;
  }
  return 0;
}
