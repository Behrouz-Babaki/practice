#include <iostream>
#include <iomanip>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::fixed;
using std::vector;


double min_cost;
bool first;
double total_distance;
double capacity;
vector<double> distances;
vector<double> prices;
int num_station;
double mpg;

double round_cents(double price);
void search(int id, bool choice, double cost, double gallons, double dist);

int main(void) {

  cin >> total_distance;
  int case_number = 1;
  while (total_distance >= 0) {
    double o_cost;
    cin >> capacity >> mpg >> o_cost;
    double cost = round_cents(capacity*o_cost);
    //check if 2-dollar-rule also applies to the first station
    cost += 2;
    cin >> num_station;
    distances.clear();
    distances.resize(num_station);
    prices.clear();
    prices.resize(num_station);
    for (int i=0; i<num_station; i++) {
      cin >> distances[i];
      cin >> prices[i];
    }
    // search (id, choice, cost)
    first = true;
    search(-1, 0, cost, capacity, 0);
    cout << "Data Set #" << case_number++ << endl;
    cout << "minimum cost = $" << fixed << setprecision(2) << min_cost/100 << endl;
    cin >> total_distance;
  }
  return 0;
}

// We are at station id, have made choice for this station. We had gallons of gas at distance dist.
void search(int id, bool choice, double cost, double gallons, double dist) {
  if (id+1 == num_station) {
    if (cost < min_cost || first)
      min_cost = cost;
    if (first)
      first = false;
    return;
  }
  gallons -= (distances[id] - dist) / mpg;
  if (choice) {
    cost += round_cents(prices[id] * (capacity - gallons));
    cost += 2;
    gallons = capacity;
    dist = distances[id];
  }
  
  double later_dist;
  if (id+1 < num_station-1) 
    later_dist = distances[id+2];
  else 
    later_dist = total_distance;
  bool stop = false, pass = false;
  if ((later_dist - dist)/mpg > gallons)
    stop = true;
  if ((distances[id+1] - dist)/mpg > capacity/2)
    pass = true;

  if (!pass) 
    search(id+1, 1, cost, gallons, dist);

  if (!stop)
    search(id+1, 0, cost, gallons, dist);
    
}


double round_cents(double price) {
  return price;
}
