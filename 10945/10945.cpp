#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::getline;
using std::vector;

bool palindromic(const string&);

int main(void) {
  string line;
  getline(cin,line);
  while (line.compare("DONE")) {
    if (palindromic(line))
      cout << "You won't be eaten!";
    else
      cout << "Uh oh..";
    cout << endl;
    getline(cin, line);
  }
  return 0;
}

bool palindromic(const string& str) {
  vector<size_t> simple;
  for (size_t counter=0, size=str.length();
       counter < size; counter++) {
    char ch = str.at(counter);
    if (ch >= 'A' &&  ch <= 'Z')
      simple.push_back(ch-'A');
    else if (ch >= 'a' && ch <= 'z')
      simple.push_back(ch-'a');
  }
  bool palindrome = true;
  for (size_t counter = 0, size = simple.size();
       palindrome && counter < size;
       counter++)
    if (simple[counter] != simple[size-1-counter])
      palindrome = false;

  return palindrome;
}
