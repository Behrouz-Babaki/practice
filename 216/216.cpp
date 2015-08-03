#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::sqrt;
using std::pow;
using std::round;
using std::setprecision;
using std::fixed;

int main(void) {
  int num_comp;
  int case_cnt = 0;
  cin >> num_comp;
  while (num_comp) {
    vector<int> coord_x(num_comp),
      coord_y(num_comp);
    for (int comp_cnt = 0; comp_cnt < num_comp; comp_cnt++)
      cin >> coord_x[comp_cnt] >> coord_y[comp_cnt];
    vector<vector<double> > dist(num_comp, vector<double> (num_comp));
    for (int i = 0; i < num_comp; i++)
      for (int j = 0; j < num_comp; j++) 
	dist[i][j] = sqrt(pow(coord_x[i] - coord_x[j], 2) + 
				pow(coord_y[i] - coord_y[j], 2)) + 16;
    
    vector<vector<double> > memo(num_comp, vector<double> (1<<num_comp));
    vector<vector<int> > path(num_comp, vector<int> (1<<num_comp));

    for (int i = 0; i < num_comp; i++)
      memo[i][(1<<num_comp)-1] = 0.0;

    for (int j = (1<<num_comp)-2; j>0; j--)
      for (int i = 0; i < num_comp; i++)
	if (j & (1<<i)) {
	  double min_dist;
	  int min_k;
	  bool first = true;
	  for (int k = 0; k < num_comp; k++)
	    if (!(j & (1<<k))) {
	      int current_set = j;
	      current_set |= (1<<k);
	      double current_dist = memo[k][current_set] + dist[i][k];
	      if (first) {
		min_dist = current_dist;
		min_k = k;
		first = false;
	      }
	      else if (min_dist > current_dist) {
		min_dist = current_dist;
		min_k = k;
	      }
	    }
	  memo[i][j] = min_dist;
	  path[i][j] = min_k;
	}


    double best_dist = memo[0][1];
    int best_start = 0;
    for (int i = 1; i < num_comp; i++)
      if (memo[i][1<<i] < best_dist) {
	best_dist = memo[i][1<<i];
	best_start = i;
      }
    
    cout << "**********************************************************" << endl;
    cout << "Network #" << ++case_cnt << endl;
    int prev = best_start;
    int set = 1 << prev;
    int next = path[prev][set];
    for (int i = 1; i < num_comp; i++) {
      cout << "Cable requirement to connect ";
      cout << "(" << coord_x[prev] << ","
	   << coord_y[prev] << ") to ("  
	   << coord_x[next] << "," 
	   << coord_y[next] << ")";
      cout << " is " << fixed << setprecision(2) << dist[prev][next] << " feet." << endl;
      prev = next;
      set |= 1 << next;
      next = path[prev][set];      
    }
    cout << "Number of feet of cable required is " << 
      fixed << setprecision(2) << best_dist << "." << endl;
    cin >> num_comp;
  }
  return 0;
}
