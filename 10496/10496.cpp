#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main(void) {
  int num_cases;
  cin >> num_cases;
  for (int case_cnt = 0; case_cnt < num_cases; case_cnt++) {
    int x_size, y_size;
    int x_start, y_start;
    int num_beepers;
    cin >> x_size >> y_size;
    cin >> x_start >> y_start;
    cin >> num_beepers;

    vector<int> b_coords_x(num_beepers), 
      b_coords_y(num_beepers);
    for (int beeper_cnt = 0; beeper_cnt < num_beepers; beeper_cnt++) 
      cin >> b_coords_x[beeper_cnt] >> b_coords_y[beeper_cnt];
    
    vector<vector<int> > dist(num_beepers, vector<int> (num_beepers));
    for (int beeper_cnt_1 = 0; beeper_cnt_1 < num_beepers; beeper_cnt_1++)
      for (int beeper_cnt_2 = 0; beeper_cnt_2 < num_beepers; beeper_cnt_2++)
	dist[beeper_cnt_1][beeper_cnt_2] = abs(b_coords_x[beeper_cnt_1] - b_coords_x[beeper_cnt_2]) 
	  + abs(b_coords_y[beeper_cnt_1] - b_coords_y[beeper_cnt_2]);

    vector<vector<int> > memo(num_beepers, vector<int> (1 << num_beepers));
    for (int pos = 0; pos < num_beepers; pos++)
      memo[pos][(1<<num_beepers)-1] = abs(b_coords_x[pos] - x_start) +
	abs(b_coords_y[pos] - y_start);

    for (int j = (1<<num_beepers)-2; j > 0; j--)
      for (int i = 0; i < num_beepers; i++) 
	if (j & (1<<i)) // i itself should be part of this subset
	  {
	    int min_dist;
	    bool first = true;
	    for (int k = 0; k < num_beepers; k++)
	      if (!(j & (1<<k))) // k should not be in the subset
	      {
		int current_set = j;
		current_set |= (1<<k);
		int current_dist;
		current_dist = memo[k][current_set] + dist[i][k];
		if (first) {
		  min_dist = current_dist;
		  first = false;
		}
		else if (min_dist > current_dist)
		  min_dist = current_dist;
	      }
	    memo[i][j] = min_dist;
	  }

    int best_dist;    
    for (int pos = 0; pos < num_beepers; pos++) {
      int current_dist = memo[pos][(1<<pos)] + abs(b_coords_x[pos] - x_start) + 
	abs(b_coords_y[pos] - y_start);
      if (!pos)
	best_dist = current_dist;
      else if (best_dist > current_dist)
	best_dist = current_dist;
    }
      
    cout << "The shortest path has length " << best_dist << endl;
  }
  return 0;
}
