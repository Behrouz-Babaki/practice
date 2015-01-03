#include <iostream>
#include <string>
#include <cmath>

using std::cout;
using std::endl;
using std::cin;
using std::ws;
using std::string;
using std::getline;
using std::sqrt;
using std::rint;

int magic(const string&);
bool ismagic(const string&, int k);

int main(void){
  string line;
  size_t num_cases;
  cin >> num_cases >> ws;
  for (size_t case_num = 1; case_num <= num_cases; case_num++) {
    getline(cin, line);
    cout << "Case #" << case_num << ":\n";
    int result = magic(line);
    if (result > 0)
      cout << result << "\n";
    else
      cout << "No magic :(\n";
  }
  return 0;
}

int magic(const string& line) {
  string simple;
  for (string::const_iterator itr = line.begin(),
	 end = line.end(); itr != end; itr++)
    if (*itr >= 'a' && *itr <= 'z')
      simple.append(1,*itr);

  double root = sqrt(simple.length());
  if (root != rint(root))
    return -1;

  if (ismagic(simple, root))
    return root;

  return -1;
}

bool ismagic(const string& str, int k) {
  bool result = true;
  
  for (size_t counter = 0, size = str.length();
       result && counter < size/2; counter++) 
    if (str.at(counter) != str.at(size-1-counter))
      result = false;
  
  size_t index = 0;
  for (size_t col = 0; result && col < k; col++)
    for (size_t row = 0; result && row < k; row++) 
      if (str.at(row*k+col) != str.at(index++))
	result = false;

  index = 0;
  for (int col = k-1; result && col >= 0; col--)
    for (int row = k-1; result && row >= 0; row--) 
      if (str.at(row*k+col) != str.at(index++))
	result = false;

  return result;
}
