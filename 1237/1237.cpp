#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::endl;
using std::cout;
using std::string;
using std::vector;

int main(void) {
  int num_cases;
  bool first = true;
  cin >> num_cases;
  while (num_cases--) {
      if (!first)
	cout << endl;
      else
	first = false;
    int d;
    cin >> d;
    vector<string> names(d);
    vector<int> high(d);
    vector<int> low(d);
    for (int counter = 0; counter < d; counter++) {
      cin >> names[counter];
      cin >> low[counter];
      cin >> high[counter];
    }
    int q;
    cin >> q;
    for (int counter = 0; counter < q; counter++) {
      int price;
      cin >> price;
      bool mult = false, found = false;
      int id = 0, m_id;
      while (id < d && !mult) {
	if (price <= high[id] && price >= low[id]) 
	  if (found)
	    mult = true;
	  else {
	    found = true;
	    m_id = id; 
	  }
	id++;
      }
      if (found && !mult)
	cout << names[m_id] << endl;
      else
	cout << "UNDETERMINED" << endl;
    }
  }
  return 0;
}
