#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::make_pair;
using std::vector;
using std::sort;

vector<int> parents, ranks;
int find_set(int);
void union_set(int, int);
double get_distance(const pair<int, int>&, 
		    const pair<int, int>&);
int main(void){
  int num_cases;
  cin >> num_cases;
  for(int case_cnt=1; case_cnt<=num_cases; case_cnt++) {
    int num_cities, threshold;
    cin >> num_cities >> threshold;
    vector<pair<int, int> > coords(num_cities);
    for (int i=0; i<num_cities; i++)  {
      int x, y;
      cin >> x >> y;
      coords[i] = make_pair(x, y);
    }

    vector<pair<double, pair<int, int> > > distances (num_cities * (num_cities-1));
    int k = 0;
    for (int i=0; i<num_cities; i++)
      for (int j=i+1; j<num_cities; j++)
	distances[k++] = make_pair(get_distance(coords[i], coords[j]),
				   make_pair(i, j));
    sort(distances.begin(), distances.end());

    parents.resize(num_cities);
    for (int i=0; i<num_cities;  i++)
      parents[i] = i;
    ranks.assign(num_cities, 0);
    int num_edges = 0;
    
    int num_states = 1;
    double road = 0, rail = 0;
    for (int i=0, s=distances.size(); num_edges<(num_cities-1) && i<s; i++) {
      pair<double, pair<int, int> > d = distances[i];
      int first = d.second.first, second = d.second.second;
      if (find_set(first) != find_set(second)) {
	union_set(first, second);
	num_edges++;
	if (d.first > threshold) {
	  rail += d.first;
	  num_states++;
	}
	else
	  road += d.first;
      }
    }
    
    cout << "Case #" << case_cnt << ": " 
	 << num_states << " " 
	 << round (road) << " " 
	 << round (rail)
	 << endl;
  }
  return 0;
}

double get_distance(const pair<int, int>& coords1, 
		    const pair<int, int>& coords2) {
  return sqrt(pow(coords1.first - coords2.first, 2) +
	      pow(coords1.second - coords2.second, 2));
}

int find_set(int id){
  if (id != parents[id])
    parents[id] = find_set(parents[id]);
  ranks[id] = 1;
  return parents[id];
}

void union_set(int first, int second){
  first = find_set(first);
  second = find_set(second);
  if (ranks[first] < ranks[second])
    parents[first] = second;
  else if (ranks[first] > ranks[second])
    parents[second] = first;
  else {
    ranks[first]++;
    parents[second] = first;
  }
}
