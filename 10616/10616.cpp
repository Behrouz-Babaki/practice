#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main(void) {
  int N, Q;
  cin >> N >> Q;
  int set_cnt = 0;
  while (N && Q) {
    vector<int> numbers(N);
    for (int num_cnt = 0; num_cnt < N; num_cnt++)
      cin >> numbers[num_cnt];
    cout << "SET " << ++set_cnt << ":" << endl;
    int D, M;
    for (int q_cnt = 0; q_cnt < Q; q_cnt++) {
      cin >> D >> M;
      vector<vector<vector<int> > > memo(N, vector<vector<int> > (M, vector<int> (D)));

      // init for j=0
      for (int i=0; i<N; i++) {
	int id; 
	if (numbers[i] > 0)
	  id = numbers[i]%D;
	else
	  id = numbers[i]%D + D;
	for (int k=0; k<D; k++)
	  if (k==id)
	    memo[i][0][k] = 1;
	  else
	    memo[i][0][k] = 0;
      }
	
      for (int i = 1; i < N; i++)
	for (int j = 1; j < M; j++)
	  for (int k = 0; k < D; k++) {
	    //compute memo[i][j][k] here
	    memo[i][j][k] = memo[i-1][j][k];
	    int id; 
	    if (numbers[i] > 0)
	      id = numbers[i]%D;
	    else
	      id = numbers[i]%D + D;
	    memo[i][j][k] += memo[i-1][j-1][id];
	  }
      cout << "QUERY " << q_cnt+1 << ": " << memo[0][M-1][0] << endl;
    }
    cin >> N >> Q;
  }
  return 0;
}

