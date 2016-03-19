#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using std::cin;
using std::endl;
using std::cout;
using std::vector;
using std::sort;
using std::pair;
using std::make_pair;

vector<int> parents;
vector<int> ranks;

int find_set(int);
void union_set(int, int);

#define viii vector<pair<int, pair<int, int> > > 
void print_vec(viii vec);

int main(void) {

  int num_computers;
  bool first = true;
  while (cin >> num_computers)
    {
      int prev_cost = 0;
      vector<pair<int, pair<int, int> > > chosen(num_computers-1);
      for (int i=0; i<num_computers-1; i++){
	int c1, c2, cost;
	cin >> c1 >> c2 >> cost;
	chosen[i] = make_pair(cost,
			      make_pair(c1-1, c2-1));
	prev_cost += cost;
      }

      int num_new;
      cin >> num_new;
      vector<pair<int, pair<int, int> > > new_lines(num_new);
      for (int i=0; i<num_new; i++) {
	int c1, c2, cost;
	cin >> c1 >> c2 >> cost;
	new_lines[i] = make_pair(cost,
				 make_pair(c1-1, c2-1));
      }

      int num_available;
      cin >> num_available;
      ranks.assign(num_available, 0);
      parents.resize(num_available);
      for (int i=0; i<num_available; i++)
	parents[i] = i;

      vector<pair<int, pair<int, int> > > avail_lines(num_available);
      for (int i=0; i<num_available; i++) {
	int c1, c2, cost;
	cin >> c1 >> c2 >> cost;
	avail_lines[i] = make_pair(cost,
				   make_pair(c1-1, c2-1));
      }
  
      new_lines.insert(new_lines.begin(), chosen.begin(), chosen.end());
      sort(new_lines.begin(), new_lines.end());
      int k=0, new_cost=0;
      for (int i=0, s=new_lines.size(); k < num_computers && i<s; i++) {
	int first, second, cost;
	cost = new_lines[i].first;
	first = new_lines[i].second.first;
	second = new_lines[i].second.second;
	if (find_set(first)!=find_set(second)) {
	  k++;
	  new_cost += cost;
	  union_set(first, second);
	}
      }
      // print_vec(avail_lines);
      if (first)
	first = false;
      else
	cout << endl;
      cout << prev_cost << endl;
      cout << new_cost << endl;

    }

  return 0;
}

int find_set(int id) {
  if (parents[id] != id)
    parents[id] = find_set(parents[id]);
  return parents[id];
}

void union_set(int first, int second){
  first = find_set(first);
  second = find_set(second);
  if (ranks[first] > ranks[second])
    parents[second] = first;
  else if (ranks[second] > ranks[first])
    parents[first] = second;
  else{
    ranks[first]++;
    parents[second] = first;
  }
}


void print_vec(viii vec){
  for (auto i : vec) 
    cout <<i.second.first << " " <<
      i.second.second <<  " " << 
      i.first << endl;
}

