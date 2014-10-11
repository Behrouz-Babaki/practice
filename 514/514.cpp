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
  bool first_line = true;
  while (N != 0) {
    if (!first_line)
      cout << endl;
    else
      first_line = false;
    vector<size_t> numbers;
    numbers.reserve(N);
    size_t current_num;
    cin >> current_num;
    while (current_num > 0) {
      numbers.push_back(current_num);
      for (size_t num_counter = 1; num_counter < N; num_counter++){
	cin >> current_num;
	numbers.push_back(current_num);
      }
      size_t current_id = 0;
      current_num = 1;
      stack<size_t> temp;

      bool success = true;
      bool done = false;
      while (!done) {
	bool found = false;
	while (!found && current_id < N){
	  if (numbers[current_id] == current_num)
	    found = true;
	  else
	    temp.push(numbers[current_id]);
	  current_id++;
	}
      
	if (!found){
	  success = false;
	  done = true;
	}
	else {
	  size_t next_num;
	  while (!done && !temp.empty()){
	    next_num = temp.top();
	    temp.pop();
	    if (next_num != current_num){
	      success = false;
	      done = true;
	    }
	    current_num++;
	  }
	}
      }
      if (success)
	cout << "Yes" << endl;
      else
	cout << "No" << endl;
      cin >> current_num;
      numbers.clear();
      numbers.reserve(N);
    }
    cin >> N;
  }
  return 0;
}
