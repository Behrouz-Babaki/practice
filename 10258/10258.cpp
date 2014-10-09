#include <iostream>
#include <sstream>
#include <string>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::istringstream;
using std::string;
using std::ws;
using std::isspace;

bool is_blank(string&);

int main (void) {
  int number_of_cases;
  string line;
  cin >> number_of_cases >> ws;
  for (int case_cnt = 0; case_cnt < number_of_cases; case_cnt++) {
    getline(cin, line);
    while (!is_blank(line)){
      size_t contestant, problem, time;
      char L;
      istringstream ss(line);
      ss >> contestant >> problem >> time >> L;


      getline(cin, line);
    }
  }
  return 0;
}

bool is_blank (string& str) {
  string::iterator itr  =  str.begin();
  while (itr != str.end())
    if (!isspace(*itr++))
      return false;
  return true;
}
