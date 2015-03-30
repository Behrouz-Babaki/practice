#include <iostream>
#include <string>
#include <vector>
#include <utility>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::pair;
using std::make_pair;

bool is_valid(const vector<int>&, const vector<int>&);
string pair_str(int, int);
bool has_comp(int, int);

int main(void) {
  string p[3];
  vector<int> abo(3);
  vector<int> rh(3);
  cin >> p[0] >> p[1] >> p[2];
  int case_cnt = 1;
  while (p[0].compare("E") || p[1].compare("N") || p[2].compare("D")) {
    int unknown;
    for (int cnt = 0; cnt < 3; cnt++)
      if (p[cnt].size() == 1 && p[cnt][0] == '?')
	unknown = cnt;
      else {
	if (p[cnt].size() == 3) 
	  abo[cnt] = 1;
	else 
	  switch(p[cnt][0]){
	  case 'A':
	    abo[cnt] = 0;
	    break;
	  case 'B':
	    abo[cnt] = 2;
	    break;
	  case 'O':
	    abo[cnt] = 3;
	    break;
	  }
	rh[cnt] = (p[cnt][p[cnt].size() - 1] == '+');
      }
    vector<pair<int,int> > valid;
    for (int abo_cnt = 0; abo_cnt < 4; abo_cnt++){
      abo[unknown] = abo_cnt;
      for (int rh_cnt = 1; rh_cnt >= 0; rh_cnt--) {
	rh[unknown] = rh_cnt;
	if (is_valid(abo, rh))
	  valid.push_back(make_pair(abo_cnt, rh_cnt));
      }
    }
    cout << "Case " << case_cnt++ << ":";
    for (int cnt = 0; cnt < 3; cnt++) 
      if (unknown != cnt)
	cout << " " << pair_str(abo[cnt], rh[cnt]);
      else if (valid.size() == 0)
	cout << " IMPOSSIBLE";
      else {
	cout << " ";
	if (valid.size() > 1)
	  cout << "{";
	for (int ind = 0, size = valid.size(); ind < size; ind++) {
	  cout << pair_str(valid[ind].first, valid[ind].second);
	  if (ind < size-1)
	    cout << ", ";
	}
	if (valid.size() > 1)
	  cout << "}";
      }
    cout << endl;
    
    cin >> p[0] >> p[1] >> p[2];
  }
  return 0;
}

bool is_valid(const vector<int>& abo, const vector<int>& rh){
  bool valid = true;
  if (rh[2] && !rh[0] && !rh[1])
    return  false;
  switch (abo[2]) {
  case 0:
    if (!(
	  (has_comp(abo[0], 0) && has_comp(abo[1], 0)) ||
	  (has_comp(abo[0], 0) && has_comp(abo[1], 2)) ||
	  (has_comp(abo[0], 2) && has_comp(abo[1], 0)))
	)
      valid = false;
    break;
  case 1:
    if (!(
	(has_comp(abo[0], 0) && has_comp(abo[1], 1)) ||
	(has_comp(abo[0], 1) && has_comp(abo[1], 0)))
	)
      valid = false;
    break;
  case 2:
    if (!(
	  (has_comp(abo[0], 1) && has_comp(abo[1], 1)) ||
	  (has_comp(abo[0], 1) && has_comp(abo[1], 2)) ||
	  (has_comp(abo[0], 2) && has_comp(abo[1], 1)))
	)
      valid = false;
    break;
  case 3:
    if (!(has_comp(abo[0], 2) && has_comp(abo[1], 2)))
      valid = false;
    break;
  }
  return valid;
}

string pair_str(int abo, int rh) {
  string st;
  if (abo == 1) {
    st.resize(3);
    st[0] = 'A';
    st[1] = 'B';
  }
  else {
    st.resize(2);
    switch(abo) {
    case 0:
      st[0] = 'A';
      break;
    case 2:
      st[0] = 'B';
      break;
    case 3:
      st[0] = 'O';
      break;
    }
  }
  st[st.size() - 1] = rh ? '+' : '-';
  return st;
}
  
//components: A=0, B=1, O=2
bool has_comp(int abo, int comp) {
  return (
	  ((abo == 0 || abo == 1) && comp == 0) ||
	  ((abo == 1 || abo == 2) && comp == 1) ||
	  ((abo == 0 || abo == 2 || abo == 3) && comp == 2)
	  );
}
