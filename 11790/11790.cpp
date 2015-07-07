#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::max_element;

int main(void) {
  int num_cases;
  cin >> num_cases;
  for (int case_cnt=0; case_cnt<num_cases; case_cnt++) {
    int N;
    cin >> N;
    vector<int> heights(N);
    vector<int> widths(N);
    for (int i=0; i<N; i++)
      cin >> heights[i];
    for (int i=0; i<N; i++)
      cin >> widths[i];

    vector<int> lis(N);
    vector<int> lds(N);
    for (int i=0; i<N; i++){
      int best_i=0, best_d = 0;
      for (int j=0; j<i; j++) {
	if (heights[j] < heights[i] && lis[j] > best_i)
	  best_i = lis[j];
	if (heights[j] > heights[i] && lds[j] > best_d)
	  best_d = lds[j];
      }
      lis[i] = best_i + widths[i];
      lds[i] = best_d + widths[i];
    }

    int I = * max_element(lis.begin(), lis.end());
    int D = * max_element(lds.begin(), lds.end());
    cout << "Case " << case_cnt+1 << ". ";
    if (I >= D)
      cout << "Increasing (" << I << "). Decreasing (" << D << ")." << endl;
    else
      cout << "Decreasing (" << D << "). Increasing (" << I << ")." << endl;
  }
  return 0;
}
