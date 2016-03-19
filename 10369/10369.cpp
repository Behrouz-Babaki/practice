#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>

using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::pair;
using std::make_pair;
using std::vector;
using std::greater;

#define ii pair<int, int> 
#define dii pair<double, ii>
#define vii vector<ii>
#define vdii vector<dii>

vii coords;
double get_distance(const ii &, 
		    const ii &);

vector<int> parents;
vector<int> ranks;
int find_set(int);
void union_set(int, int);

int main(void) {
  int num_cases;
  cin >> num_cases;
  while (num_cases--){
    int num_sat, num_post;
    cin >> num_sat >> num_post;

    coords.clear();
    coords.resize(num_post);
    for (int i=0; i<num_post; i++) {
      int x, y;
      cin >> x >> y;
      coords[i] = make_pair(x, y);
    }
    vdii distances(num_post*(num_post-1)/2);
    int k=0;
    for (int i=0; i<num_post; i++) 
      for (int j=i+1; j<num_post; j++) {
	double d = get_distance(coords[i], coords[j]);
	distances[k++] = make_pair(d, make_pair(i, j));
    }
    sort(distances.begin(), distances.end());
    
    ranks.assign(num_post, 0);
    parents.resize(num_post);
    for (int i=0; i<num_post; i++)
      parents[i] = i;

    // MST
    int num_edges = 0;
    vector<double> edge_costs(num_post-1);
    for (int i=0, s=distances.size(); num_edges < (num_post-1) && i<s; i++) {
      double dist = distances[i].first;
      int first = distances[i].second.first, second = distances[i].second.second;
      if(find_set(first) != find_set(second)) {
	edge_costs[num_edges] = dist;
	num_edges++;
	union_set(first, second);
      }
    }
    sort(edge_costs.begin(), edge_costs.end(), greater<double>());
    printf("%.2f\n", edge_costs[num_sat-1]);
  }
  return 0;
}

double get_distance(const ii & first, 
		    const ii & second) {
  double x_d = first.first - second.first;
  double y_d = first.second - second.second;
  return sqrt(x_d*x_d + y_d*y_d);
}

int find_set(int id){
  if (parents[id]!=id)
    parents[id] = find_set(parents[id]);
  return parents[id];
}

void union_set(int first, int second) {
  first = find_set(first);
  second = find_set(second);
  if (ranks[first] < ranks[second])
    parents[first] = second;
  else if (ranks[second] < ranks[first])
    parents[second] = first;
  else {
    ranks[first] ++;
    parents[second] = first;
  }
}
