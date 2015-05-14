#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::sort;

int main(void){
  int num_bags;
  cin >> num_bags;
  while (num_bags) {
    vector<int> bags(num_bags);
    for (int cnt=0; cnt<num_bags; cnt++)
      cin >> bags[cnt];
    sort(bags.begin(), bags.end());
    int id = 0, max = 0, count = 0;
    while (id < bags.size()) {
      count = 0;
      bool done = false;
      while(!done){
	count++;
	id++;
	if (id >= bags.size() ||
	    bags[id]!=bags[id-1])
	  done = true;
      }
      if (count > max)
	max = count;
    }

    vector<vector<int> > collections(max);
    id=0;
    while (id < bags.size()){
      int col_cnt = 0;
      bool done = false;
      vector<bool> used(max, false);
      while(!done){
	int min_ind = 0;
	for (int cnt=0; cnt<max; cnt++)
	  if (!used[cnt] &&
	      collections[cnt].size() < collections[min_ind].size()){
	    min_ind = cnt;
	  }
	collections[min_ind].push_back(bags[id]);
	used[min_ind] = true;
	col_cnt++;
	id++;
	if (id >= bags.size() || bags[id]!=bags[id-1])
	  done = true;
      }
    }

    cout << collections.size() << endl;
    for (auto collection : collections){
      int size = collection.size();
      for (int cnt=0; cnt<size; cnt++) {
	if (cnt)
	  cout << " ";
	cout << collection[cnt];
      }
      cout << endl;
    }
    cin >> num_bags;
    if (num_bags)
      cout << endl;
  }
  return 0;
}
