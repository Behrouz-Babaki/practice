#include <iostream>
#include <string> 
#include <algorithm>

using std::endl;
using std::cout;
using std::cin;
using std::string;
using std::sort;
using std::next_permutation;
using std::ws;

int main(void) {
  size_t num_cases;
  cin >> num_cases;
  for (size_t case_counter = 0; case_counter < num_cases; case_counter++) {
    string word;
    cin >> word;
    sort(word.begin(), word.end(), Compare_195());
    do {
      cout << word << endl;
    } while (next_permutation(word.begin(), word.end(), Compare_195()));
  }
  return 0;
}
