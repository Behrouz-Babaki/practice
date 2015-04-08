#include <iostream>
#include <iomanip>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::fixed;
using std::vector;

int main(void) {
  double distance;
  cin >> distance;
  int case_number = 1;
  while (distance >= 0) {
    double capacity, mpg, o_cost;
    cin >> capacity >> mpg >> o_cost;
    int num_station;
    cin >> num_station;
    vector<double> distances(num_station);
    vector<double> prices(num_station);
    for (int i=0; i<num_station; i++) {
      cin >> distances[i];
      cin >> prices[i];
    }
    double min_cost = 0;
    //write your code here
    cout << "Data Set #" << case_number++ << endl;
    cout << "minimum cost = $" << fixed << setprecision(2) << min_cost/100 << endl;
    cin >> distance;
  }
  return 0;
}
