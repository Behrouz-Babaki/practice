#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;

int main(void) {
  string p1, p2, child;
  cin >> p1 >> p2 >> child;
  while (p1.compare("E") || p2.compare("N") || child.compare("D")) {
    
    cin >> p1 >> p2 >> child;
  }
  return 0;
}
