#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

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
vector<int> v;

double round_cents(double price);
void search(int id, double cost, double gallons, double dist);

int main(void) {

  cin >> total_distance;
  int case_number = 1;
  while (total_distance >= 0) {
    double o_cost;
    cin >> capacity >> mpg >> o_cost;
    double cost = round_cents(o_cost);
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
    v.clear();
    search(0, cost, capacity, 0);
    cout << "Data Set #" << case_number++ << endl;
    cout << "minimum cost = $" << fixed << setprecision(2) << min_cost << endl;
    cin >> total_distance;
  }
  return 0;
}

// We are at station id. We had gallons of gas at distance dist.
void search(int id, double cost, double gallons, double dist) {
  if (id == num_station) {
    if (cost < min_cost || first) {
      min_cost = cost;
      // for (auto vv : v)
      // 	cout << vv << "-";
      // cout << "> " << min_cost << endl;
    }
    if (first)
      first = false;
    return;
  }

  double later_dist;
  if (id+1 < num_station) 
    later_dist = distances[id+1];
  else 
    later_dist = total_distance;

  bool stop = false, pass = false;
  if ((later_dist - dist)/mpg > gallons)
    stop = true;
  if (!stop && (distances[id] - dist)/mpg < capacity/2)
    pass = true;

  if (!pass) {
    double new_cost = cost;
    double remaining = gallons - (distances[id] - dist)/mpg;
    new_cost += round_cents(prices[id] * (capacity - remaining)/100);
    new_cost += 2;
    v.push_back(id);
    search(id+1, new_cost, capacity, distances[id]);
    v.pop_back();
  }

  if (!stop)
    search(id+1, cost, gallons, dist);
    
}


double round_cents(double price) {
  return round(price*100)/100;
}
