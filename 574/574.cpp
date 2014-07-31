#include <iostream>
#include <vector>
#include <utility>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::pair;
using std::make_pair;

vector<pair<int,int> > input;
vector<int> maxLeft;

void printSums (int, int, const vector<int>&);
int main (void) {
  int t, n;
  cin >> t;
  cin >> n;

  while (n != 0) {
    vector<int> x(n);
    for (int counter =0; counter < n; counter++)
      cin >> x[counter];

    initializeGlobals();
    
    cout << "Sums of " << t << ":" << endl;
    printSums (t, n, x);

    cin >> t;
    cin >> n;
  }
  return 0;
}

void printSums (int t, int n, const vector<int>& x){
  cout << "NONE" << endl;
}

void func (int t, int n, int partial_sum, vector<int>& selected){

  //It only remains to update the maxLeft
  if (partial_sum == t)
    printComponents(selected);

  if (partial_sum > t)
    return;

  int position = selected.size();
  int val = x[position].first;
  int num = x[position].second;
  int currentPartail = partial_sum;

  for (int counter = 1; counter <= num; counter++) {
    currentPartail += val;
    selected.push_back(counter);
    func (t, n, currentPartail, selected);
    selected.pop_back();
  }

}


void printComponents (const vector<int>& selected) {
  int size = selected.size();
  for (int counter = 0; counter < size; counter++) {
    for (int elemCounter = 0; elelmCounter < selected[counter]; elemCounter++) {
      cout << input[counter].first;
      if (elemCounter < selected[counter] - 1)
	cout << "+";
    }
    if (counter < size - 1)
      cout << "+";
  }
}
