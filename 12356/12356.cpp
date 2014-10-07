#include <iostream>
#include <list> 

using std::list;
using std::cin;
using std::cout;
using std::endl;

int main(void) {

  size_t num_soldiers, num_reports;
  cin >> num_soldiers >> num_reports;

  while (num_soldiers > 0 && num_reports > 0) {
    list<size_t> soldiers (num_soldiers);
    size_t soldier_cnt = 1;

    for (list<size_t>::iterator itr = soldiers.begin(), end_itr = soldiers.end();
	 itr != end_itr; itr++, soldier_cnt++)
      *itr = soldier_cnt;

    size_t first, last, before_first, after_last;
    for (size_t report_cnt = 0; report_cnt < num_reports; report_cnt++){
      cin >> first >> last;
      list<size_t>::iterator first_itr, last_itr;
      bool found = false;
      first_itr = soldiers.begin();
      while (!found)
	if (*first_itr == first) {
	  found = true;
	}
	else
	  first_itr++;

      if (first_itr == soldiers.begin())
	before_first = 0;
      else {
	first_itr--;
	before_first = *first_itr;
	first_itr++;
      }

      bool finished = false;
      last_itr = first_itr;
      while(!finished){
	if (*last_itr == last)
	  finished = true;
	last_itr = soldiers.erase(last_itr);
      }
      
      if (!before_first)
	cout << "*";
      else
	cout << before_first;
      
      cout << " ";

      if (last_itr == soldiers.end())
	cout << "*";
      else
	cout << *(last_itr++);

      cout << endl;
    }
    cout << "-" << endl;
    cin >> num_soldiers >> num_reports;
  }
  return 0;
}
