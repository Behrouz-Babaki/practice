#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::sort;

int main(void) {
  int num_b, num_s;
  int case_cnt = 0;
  cin >> num_b >> num_s;
  while (num_b || num_s) {

    vector<int> b(num_b);
    for (int i=0; i<num_b; i++) 
      cin >> b[i];
    sort (b.begin(), b.end(), 
	  [](int l,int r){return l > r;});

    vector<int> s(num_s);
    for (int i=0; i<num_s; i++) 
      cin >> s[i];
    sort (s.begin(), s.end(), 
	  [](int l, int r){return l > r;});
    
    vector<bool> married(num_s);
    int num_married = 0;
    int id = 0;
    while (id < num_b  && num_married < num_s){
      bool done = false;
      bool found = false;
      int match_id;
      int s_id = num_s-1;
      while (!done){
	if (!married[s_id])
	  match_id = s_id;

	s_id--;
	if (s_id < 0)
	  done = true;
	if (s_id > 0 && 
	    s[s_id] < b[id]) {
	  done = true;
	  if (!married[s_id] &&
	      abs(b[id]-s[s_id]) < 
	      abs(b[id]-s[match_id]))
	    match_id = s_id;
	}
      }
      married[match_id] = true;
      num_married++;
      id++;
    }
    
    case_cnt++;
    cout << "Case " << case_cnt << ": " << (num_b - id);
    if (id < num_b)
      cout << " " << b[num_b-1];
    cout << endl;
    cin >> num_b >> num_s;
  }
  return 0;
}
