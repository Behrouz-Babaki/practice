#include <iostream>
#include <vector>

using std::endl;
using std::cin;
using std::cout;
using std::vector;

int main(void) {
  int num_routes;
  cin >> num_routes;
  for (int i=0; i<num_routes; i++){
    int num_segments;
    cin >> num_segments;
    num_segments--;
    vector<int> niceness(num_segments);
    vector<int> acc_nice(num_segments);
    vector<int> acc_len(num_segments);

    for (int j=0; j<num_segments; j++)
      cin >> niceness[j];
    for (int j=num_segments-1; j>=0; j--){
      acc_nice[j] = niceness[j];
      acc_len[j] = 1;
      if (j < num_segments-1 && acc_nice[j+1] >= 0){
	acc_nice[j] += acc_nice[j+1];
	acc_len[j] += acc_len[j+1];
      }
    }
    
    int max_nice = 0;
    int max_id = -1;
    int max_len = 0;
    for (int j=0; j<num_segments; j++) 
      if (acc_nice[j] > max_nice ||
	  (acc_nice[j] == max_nice &&
	   acc_len[j] > max_len)){
	max_id = j;
	max_nice = acc_nice[j];
	max_len = acc_len[j];
      }

    if (max_nice == 0)
      cout << "Route " << i+1 << " has no nice parts" << endl;
    else
      cout << "The nicest part of route " << i+1 << " is between stops " 
	   << max_id + 1 << " and " << max_id + max_len + 1 << endl;
  }
  return 0;
}
