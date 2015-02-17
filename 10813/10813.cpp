#include <iostream>
#include <vector>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::map;

int main(void) {
  size_t num_cases;
  cin >> num_cases;
  for (size_t case_counter = 0; case_counter < num_cases; case_counter++) {
    vector<size_t> card(25);
    vector<bool> marked(25, false);
    map<size_t, size_t> loc_map;
    size_t card_num;
    for (size_t card_num_counter = 0; card_num_counter < 25; card_num_counter++) {
      if (card_num_counter == 12)
	card_num_counter++;
      cin >> card_num;
      card[card_num_counter] = card_num;
      loc_map[card_num] = card_num_counter;
    }
    size_t announced_num;
    bool found = false;
    marked[12] = true;
    for (size_t announced_num_counter = 0; announced_num_counter < 75; announced_num_counter++) {
      cin >> announced_num;
      if (!found && loc_map.find(announced_num) != loc_map.end()) {
	size_t location = loc_map[announced_num];
	marked[location] = true;
	size_t row = location / 5;
	size_t col = location - (row * 5);
	bool full_row = true, full_col = true, full_diag1 = true, full_diag2 = true;
	for (int current_col = col -1; full_col && current_col >= 0; current_col--) {
	  size_t current_location = (5*row) + current_col;
	  if (!marked[current_location])
	    full_col = false;
	}

	for (int current_col = col + 1; full_col && current_col < 5; current_col++) {
	  size_t current_location = (5*row) + current_col;
	  if (!marked[current_location])
	    full_col = false;
	}

	if (!full_col) {
	  for (int current_row = row -1; full_row && current_row >= 0; current_row--) {
	    size_t current_location = (5*current_row) + col;
	    if (!marked[current_location])
	      full_row = false;
	  }

	  for (int current_row = row + 1; full_row && current_row < 5; current_row++) {
	    size_t current_location = (5*current_row) + col;
	    if (!marked[current_location])
	      full_row = false;
	  }

	  if (!full_row && !full_col) {
	    if (row == col) {
	      //cout << "row:" << row << "\tcol:" << col << endl;
	      for (int current_d = row -1; full_diag1 && current_d >= 0; current_d--) {
		size_t current_location = (5*(current_d)) + current_d;
		if (!marked[current_location])
		  full_diag1 = false;
	      }

	      for (int current_d = row+1; full_diag1 && current_d < 5; current_d++) {
		size_t current_location = (5*(current_d)) + current_d;
		if (!marked[current_location])
		  full_diag1 = false;
	      }
	    }
	    else 
	      full_diag1 = false;
	
	    if (!full_diag1) {
	      if (row + col != 4)
		full_diag2 = false;
	      else {
		for (int current_d = row-1; full_diag2 && current_d >= 0; current_d--) {
		  size_t current_location = (5*(current_d)) + (4-current_d);
		  if (!marked[current_location])
		    full_diag2 = false;
		}
		for (int current_d = row+1; full_diag2 && current_d <5 ; current_d++) {
		  size_t current_location = (5*(current_d)) + (4-current_d);
		  if (!marked[current_location])
		    full_diag2 = false;
		}
	      }
	    }
	    
	  }
	}
	if (full_col || full_row || full_diag1 || full_diag2) {
	  cout << "BINGO after " << announced_num_counter+1 << " numbers announced" << endl;
	  // cout << full_col << full_row << full_diag1 << full_diag2 << endl;
	  found = true;
	}
	
      }
    }
    
  }
  return 0;
}
