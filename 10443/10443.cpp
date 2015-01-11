#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::ws;
using std::endl;
using std::string;
using std::getline;
using std::vector;

bool beats(char, char);

int main(void) {
  size_t num_cases;
  cin >> num_cases >> ws;
  for (size_t case_counter = 0; case_counter < num_cases; case_counter++) {
    size_t r, c, n;
    cin >> r >> c >> n >> ws;
    vector<vector<char> > current (r, vector<char>(c));
    vector<vector<char> > next (r, vector<char>(c));    

    for (size_t row_counter = 0; row_counter < r; row_counter++) {
      for(size_t col_counter = 0; col_counter < c; col_counter++) 
	cin.get(current[row_counter][col_counter]);
      cin.ignore();
    }
    
    for (size_t timer = 0; timer < n; timer++) {
      for (size_t row_counter = 0; row_counter < r; row_counter++) {
	for(size_t col_counter = 0; col_counter < c; col_counter++) {
	  next[row_counter][col_counter] = current[row_counter][col_counter];
	  if (col_counter > 0 && 
	      beats(current[row_counter][col_counter-1], current[row_counter][col_counter]))
	    next[row_counter][col_counter] = current[row_counter][col_counter-1];
	  if (col_counter < c-1 && 
	      beats(current[row_counter][col_counter+1], current[row_counter][col_counter]))	    
	    next[row_counter][col_counter] = current[row_counter][col_counter+1];
	  if (row_counter > 0 && 
	      beats(current[row_counter-1][col_counter], current[row_counter][col_counter]))	    
	    next[row_counter][col_counter] = current[row_counter-1][col_counter];
	  if (row_counter < r-1 && 
	      beats(current[row_counter+1][col_counter], current[row_counter][col_counter]))	    
	    next[row_counter][col_counter] = current[row_counter+1][col_counter];
	}
      }
      current = next;
    }

    for (size_t row_counter = 0; row_counter < r; row_counter++) {
      for(size_t col_counter = 0; col_counter < c; col_counter++) 
	cout << current[row_counter][col_counter];
      cout << endl;
    }
    if (case_counter < num_cases-1)
      cout << endl;
  }
  return 0;
}

bool beats(char winner, char loser) {
  return ((winner == 'R' && loser == 'S') ||
	  (winner == 'S' && loser == 'P') ||
	  (winner == 'P' && loser == 'R'));
}
