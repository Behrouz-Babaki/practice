#include <iostream>
#include <vector>
#include <set>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::set;

int main(void) {
  set<int> scores;
  scores.insert(0);
  for (int mult = 1; mult <= 3; mult++)
    for (int c = 1; c <= 20; c++)
      scores.insert(mult*c);
  scores.insert(50);

  int score;
  cin >> score;
  while (score > 0) {
    int num_comb = 0;
    int num_perm = 0;
    // two or three same
    for (set<int>::iterator itr = scores.begin(); itr != scores.end(); itr++) {
      int third = score - 2 * (*itr);
      if(scores.find(third) != scores.end()){
	//cout << *itr << " " << *itr << " " << third << endl;
	  num_comb++;
	  if (third == *itr)
	    num_perm++;
	  else 
	    num_perm += 3;
      }
	
    }
    for (set<int>::iterator itr1 = scores.begin(); itr1 != scores.end(); itr1++){
      set<int>::iterator itr2 = itr1;
      itr2++;
      for (; itr2 != scores.end() && score - *itr1 - *itr2 > *itr2; itr2++)
	if (scores.find(score - *itr1 - *itr2) != scores.end()) {
	  //cout << *itr1 << " " << *itr2 << " " << score - *itr1 - *itr2 << endl;
	  num_comb++;
	  num_perm += 6;
	}
    }

    if (num_comb) {
      cout << "NUMBER OF COMBINATIONS THAT SCORES " << score << " IS " << num_comb << "." << endl;
      cout << "NUMBER OF PERMUTATIONS THAT SCORES " << score << " IS " << num_perm << "." << endl;
    }
    else
      cout << "THE SCORE OF " << score <<" CANNOT BE MADE WITH THREE DARTS." << endl;
    cout << "**********************************************************************" << endl;
    cin >> score;
  }
  cout << "END OF OUTPUT" << endl;
  return 0;
}
