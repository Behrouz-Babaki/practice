#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::sort;
using std::set;

int main(void){
  int num_bags;
  cin >> num_bags;
  while (num_bags) {
    vector<int> bags(num_bags);
    for (int cnt=0; cnt<num_bags; cnt++)
      cin >> bags[cnt];
    sort(bags.begin(), bags.end());

    vector<vector<int> > collections;
    while(bags.size() > 0){
      vector<int> collected;
      set<int> removed;
      for (int i=0; i<bags.size(); i++)
	if (collected.empty() || 
	    bags[i] > collected.back()){
	  collected.push_back(bags[i]);
	  removed.insert(i);
	}

      collections.push_back(collected);

      vector<int> bags_copy;
      for (int i=0; i<bags.size(); i++)
	if (removed.find(i)==removed.end())
	  bags_copy.push_back(bags[i]);
      bags = bags_copy;
    }
    cout << collections.size() << endl;
    for (auto collection : collections){
      for (auto bag : collection)
	cout << bag << " ";
      cout << endl;
    }
    cin >> num_bags;
    if (num_bags)
      cout << endl;
  }
  return 0;
}
