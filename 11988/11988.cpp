#include <iostream>
#include <list> 
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::list;
using std::string;

int main(void) {
  string line;
  while(getline(cin, line)) {
    list<char> out;
    list<char>::iterator itr = out.begin();
    for (auto ch : line) 
      switch(ch) {
      case '[':
	itr = out.begin();
	break;
      case ']':
	itr = out.end();
	break;
      default:
	out.insert(itr, ch);
	break;
      }
    for (auto ch : out)
      cout << ch;
    cout << endl;
  }
  return 0;
}
