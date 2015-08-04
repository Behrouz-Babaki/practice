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
      vector<vector<vector<int> > > memo(N+1, vector<vector<int> > (M+1, vector<int> (D,0)));

      // init for i=N
      for (int j=0; j<=M; j++)
	for (int k=0; k<D; k++)
	  memo[N][j][k] = 0;

      // init for j=0
      for (int i=0; i<=N; i++) 
	    memo[i][0][0] = 1;

      for (int i = N-1; i>=0; i--)
	for (int j = 1; j <= M; j++)
	  for (int k = 0; k < D; k++) {
	    //compute memo[i][j][k] here
	    memo[i][j][k] = memo[i+1][j][k];
	    int rem = numbers[i]%D;
	    if (rem < 0)
	      rem += D;
	    int id = k - (rem);
	    if (id < 0)
	      id += D;
	    memo[i][j][k] += memo[i+1][j-1][id];
	  }
      cout << "QUERY " << q_cnt+1 << ": " << memo[0][M][0] << endl;
    }
    cin >> N >> Q;
  }
  return 0;
}

