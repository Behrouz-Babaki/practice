#include <iostream>
#include <vector>
#include <utility>

using std::cout;
using std::cin;
using std::flush;
using std::endl;
using std::vector;
using std::pair;
using std::make_pair;

vector<pair<int,int> > input;
vector<int> maxLeft;
int t;
int n;
int numWays;

void search (int, vector<int>&);
void printComponents (const vector<int>&);

int main (void) {

  cin >> t;
  cin >> n;

  while (n != 0) {

    numWays = 0;
    input.clear();
    maxLeft.clear();

    vector<int> x(n);
    for (int counter =0; counter < n; counter++)
      cin >> x[counter];

    int prev = x[0];
    int reps = 1;
    for (int counter = 1; counter < x.size(); counter++) {
      if (x[counter] == prev)
	reps ++;
      else {
	input.push_back(make_pair (prev, reps));
	reps = 1;
      }
      prev = x[counter];
    }
    input.push_back(make_pair (prev, reps));

    maxLeft.resize(input.size());
    int remaining = 0;
    for (int counter = input.size() - 1; counter >= 0; counter--){
      maxLeft[counter] = remaining + input[counter].first * input[counter].second;
      remaining = maxLeft[counter];
    }
    
    cout << "Sums of " << t << ":" << endl;
    vector<int> selected;
    search (0, selected);
    if (numWays == 0)
      cout << "NONE" << endl;

    cin >> t;
    cin >> n;
  }
  return 0;
}

void search (int partial_sum, vector<int>& selected){

  if (partial_sum == t) {
    printComponents(selected);
    numWays++;
    return;
  }

  if (selected.size() == input.size())
    return;

  if (maxLeft[selected.size()] < (t - partial_sum))
    return;

  int position = selected.size();
  int val = input [position].first;
  int num = input [position].second;
  int currentPartail;

  for (int counter = num; counter >= 0 ; counter--) {
    currentPartail = partial_sum + val * counter;
    selected.push_back(counter);
    search (currentPartail, selected);
    selected.pop_back();
  }
}


void printComponents (const vector<int>& selected) {
  int size = selected.size();
  for (int counter = 0; counter < size; counter++) 
    if (selected[counter]){
    for (int elemCounter = 0; elemCounter < selected[counter]; elemCounter++) {
      cout << input[counter].first;
      if (elemCounter < selected[counter] - 1)
	cout << "+";
    }
    if (counter < size - 1)
      cout << "+";
  }
  cout << endl;
}

