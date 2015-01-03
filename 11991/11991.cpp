#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main(void) {
  int num_elements, num_queries;
  while (cin >> num_elements) {
    cin >> num_queries;
    vector<vector<int> > elements(1000001);
    for (int elem_cnt = 1; elem_cnt <= num_elements; elem_cnt++) {
      int element;
      cin >> element;
      elements[element].push_back(elem_cnt);
    }
    for (int query_cnt = 0; query_cnt < num_queries; query_cnt++){
      int number, occurence;
      cin >> occurence >> number;
      if (occurence > elements[number].size())
	cout << 0;
      else
	cout << elements[number][occurence-1];
      cout << endl;
    }
  }
  return 0;
}
