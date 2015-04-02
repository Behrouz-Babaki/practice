#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

int main(void) {
  int N, n;
  cin >> N >> n;
  while (N && n) {
    vector<vector<char> >  big(N, vector<char>(N)), small(n, vector<char>(n));
    string line;
    for (int cnt=0; cnt < N; cnt++) {
      cin >> line;
      for (int ch_cnt = 0; ch_cnt < N; ch_cnt++)
	big[cnt][ch_cnt] = line[ch_cnt];
    }
    for (int cnt=0; cnt < n; cnt++) {
      cin >> line;
      for (int ch_cnt = 0; ch_cnt < n; ch_cnt++)
	small[cnt][ch_cnt] = line[ch_cnt];
    }
    int t0 = 0, 
      t90 = 0,
      t180 = 0,
      t270 = 0;
    bool match = true;
    for (int big_cnt_row = 0; big_cnt_row <= N-n; big_cnt_row++)
      for (int big_cnt_col = 0; big_cnt_col <= N-n; big_cnt_col++){
	int big_current_row, big_current_col;
	match = true;
	for (int small_cnt_row = 0, big_current_row = big_cnt_row; match && small_cnt_row < n; small_cnt_row++, big_current_row++)
	  for (int small_cnt_col = 0, big_current_col = big_cnt_col; match&& small_cnt_col < n; small_cnt_col++, big_current_col++)
	    if (big[big_current_row][big_current_col] != 
		small[small_cnt_row][small_cnt_col])
	      match = false;

	if (match) 
	  t0++;


	match = true;
	for (int small_cnt_col = 0, big_current_row = big_cnt_row; match&& small_cnt_col < n; small_cnt_col++, big_current_row++)
	  for (int small_cnt_row = n-1, big_current_col = big_cnt_col; match && small_cnt_row >= 0; small_cnt_row--, big_current_col++)
	      if (big[big_current_row][big_current_col] != 
		  small[small_cnt_row][small_cnt_col])
		match = false;

	  if (match)
	    t90++;


	match = true;
	for (int small_cnt_row = n-1, big_current_row = big_cnt_row; match && small_cnt_row >= 0; small_cnt_row--, big_current_row++)
	  for (int small_cnt_col = n-1, big_current_col = big_cnt_col; match&& small_cnt_col >= 0; small_cnt_col--, big_current_col++)
	    if (big[big_current_row][big_current_col] != 
		small[small_cnt_row][small_cnt_col])
	      match = false;

	if (match)
	  t180++;

	match = true;
	for (int small_cnt_col = n-1, big_current_row = big_cnt_row; match&& small_cnt_col >= 0; small_cnt_col--, big_current_row++)
	  for (int small_cnt_row = 0, big_current_col = big_cnt_col; match && small_cnt_row < n; small_cnt_row++, big_current_col++)
	    if (big[big_current_row][big_current_col] != 
		small[small_cnt_row][small_cnt_col])
	      match = false;

	if (match)
	  t270++;
      }
    cout << t0 << " " << t90 << " " << t180 << " " << t270 << endl;
    cin >> N >> n;
  }
  return 0;
}
