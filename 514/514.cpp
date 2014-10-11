#include <iostream>
#include <vector>
#include <stack>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::stack;

int main(void) {
  size_t N;
  cin >> N;
  while (N != 0) {
    vector<size_t> numbers;
    numbers.reserve(N);
    size_t current_num;
    cin >> current_num;
    while (current_num > 0) {

      stack<size_t> right_train;
      for (size_t num_counter = N; num_counter > 0; num_counter--)
	right_train.push(num_counter);
      
      numbers.push_back(current_num);
      for (size_t num_counter = 1; num_counter < N; num_counter++){
	cin >> current_num;
	numbers.push_back(current_num);
      }

      size_t current_id = 0;
      bool success = true;
      bool done = false;
      stack<size_t> temp;
      while (!done) {
	while (current_id < N && !temp.empty() && temp.top() == numbers[current_id]) {
	  temp.pop();
	  current_id ++;
	}
	if (current_id < N) {
	  while (!right_train.empty() && right_train.top() != numbers[current_id]) {
	    temp.push(right_train.top());
	    right_train.pop();
	  }
	if (!right_train.empty()) 
	  right_train.pop();
	else{
	  done = true;
	  success = false;
	}
	current_id++;
	}
	if (current_id == N)
	  done = true;
      }
      if (success)
	cout << "Yes" << endl;
      else
	cout << "No" << endl;
      cin >> current_num;
      numbers.clear();
      numbers.reserve(N);
    }
    cout << endl;
    cin >> N;
  }
  return 0;
}
