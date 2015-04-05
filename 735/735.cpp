#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main(void) {
  int score;
  cin >> score;
  while (score > 0) {
    int num_comb = 0;
    //not considering zeros though
    for (int mult1 = 1; mult <= 3; mult++)
      for (int c1 = 1; c1 <= 20; c1++)
	for (int mult2 = 1; mult2 <= 3; mult2++)
	  for (int c2 = 1; (mult*c1 + mult2*c2) <= score && c2 <= 20; c2++)
	    num_comb++;
	    
    cout << "NUMBER OF COMBINATIONS THAT SCORES " << score << " IS " << num_comb << "." << endl;
    cout << "**********************************************************************" << endl;
    cin >> score;
  }
  cout << "END OF OUTPUT" << endl;
  return 0;
}
