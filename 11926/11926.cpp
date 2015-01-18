#include <iostream>
#include <bitset>

using std::cin;
using std::cout;
using std::endl;
using std::bitset;

int main(void) {
  size_t n, m;
  cin >> n >> m;

  while (n > 0 || m > 0) {
    bitset<1000001> times;
    bool conflict = false;
    for (size_t nonrep_cnt = 0; nonrep_cnt < n; nonrep_cnt++) {
      size_t start, end;
      cin >> start >> end;
      for (size_t i = start; !conflict && i < end; i++)
	{
	  if(times[i])
	    conflict = true;
	  else
	    times[i] = 1;
	}
    }

    for (size_t rep_cnt = 0; rep_cnt < m; rep_cnt++) {
      size_t start, end, interval;
      cin >> start >> end >> interval;
      size_t length = end - start;
      size_t pointer = start;
      while (!conflict && pointer <= 1000000) {
	for (size_t cnt = 0, temp_ptr = pointer; 
	     temp_ptr <= 1000000 && cnt < length; 
	     cnt++, temp_ptr++)
	  {
	    if (times[temp_ptr])
	      conflict = true;
	    else 
	      (times[temp_ptr]) = 1;
	  }
	pointer += interval;
      }
    }

    if (!conflict)
      cout << "NO ";
    cout << "CONFLICT" << endl;
    cin >> n >> m;
  }
  return 0;
}
