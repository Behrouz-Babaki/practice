#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main(void) {
  size_t dim;
  while (cin >> dim) {
    size_t num_corners = 1 << dim;
    vector<size_t> weights(num_corners);
    vector<size_t> potencies(num_corners);

    for (size_t cnt = 0; cnt < num_corners; cnt++)
      cin >> weights[cnt];

    for (size_t cnt = 0; cnt < num_corners; cnt++) {
      potencies[cnt] = 0;
      for (size_t current_dim = 0; current_dim < dim; current_dim++) 
	potencies[cnt] += weights[cnt ^(1<<current_dim)];
    }

    size_t max_sum = 0, pair_sum;
    for (size_t cnt = 0; cnt < num_corners; cnt++) 
      for (size_t current_dim = 0; current_dim < dim; current_dim++)  {
	pair_sum = potencies[cnt] + potencies[cnt ^(1<<current_dim)];
	if (max_sum < pair_sum)
	  max_sum = pair_sum;
    }

    cout << max_sum << endl;
  }
  return 0;
}
