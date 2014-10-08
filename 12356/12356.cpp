#include <iostream>
#include <list> 
#include <utility>

using std::list;
using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::make_pair;

int main(void) {

  size_t num_soldiers, num_reports;
  cin >> num_soldiers >> num_reports;

  while (num_soldiers > 0 && num_reports > 0) {
    list <pair<size_t,size_t> > blocks;
    blocks.push_back(make_pair(1, num_soldiers));
    for (size_t report_cnt = 0; report_cnt < num_reports; report_cnt++) {
      size_t left, right;
      cin >> left >> right;
      
      list<pair<size_t,size_t> >::iterator itr;
      size_t containing_block;
      size_t block_cnt, num_blocks;
      bool found;

      found = false;
      itr = blocks.begin();
      while (!found)
	if (left >= itr->first &&
	    right <= itr->second)
	  found = true;
	else
	  itr++;
      
      bool is_first, is_last;
      is_first = false;
      is_last = false;
      size_t left_buddy, right_buddy;

      if (left > itr->first) {
	blocks.insert (itr, make_pair(itr->first, left-1));
	left_buddy = left-1;
      }
      else {
	if (itr == blocks.begin())
	  is_first = true;
	else {
	  itr--;
	  left_buddy = itr->second;
	  itr++;
	}
      }

      if (right < itr->second) {
	blocks.insert (itr, make_pair(right+1, itr->second));
	right_buddy = right + 1;
      }
      else {
	itr++;
	if (itr == blocks.end())
	  is_last = true;
	else
	  right_buddy = itr->first;
	itr--;
      }

      blocks.erase(itr);
      
      if (is_first)
	cout << "*";
      else 
	cout << left_buddy;
      cout << " ";
      if (is_last)
	cout << "*";
      else
	cout << right_buddy;
      cout << endl;
    }
    cout << "-" << endl;
    cin >> num_soldiers >> num_reports;
  }
  return 0;
}
