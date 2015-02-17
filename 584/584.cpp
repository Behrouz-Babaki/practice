#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::istringstream;
using std::vector;


int main(void) {
  string line;
  getline(cin, line);
  while(line.compare("Game Over")) {
    istringstream ss(line);
    vector<size_t> type; // <- 0:normal 1:spare 2:strike
    vector<size_t> num_down;
    size_t last_frame = 0;
    while (ss.good()) {
      char ch;
      ss >> ch;
      if (!ss.fail()) {
	switch(ch) {
	case 'X':
	  type.push_back(2);
	  num_down.push_back(10);
	  break;
	case '/':
	  type.push_back(1);
	  num_down.push_back(10 - num_down.back());
	  break;
	default:
	  type.push_back(0);
	  num_down.push_back((size_t)(ch)-48);
	  break;
	}
      }
    }

    size_t total_score = 0;
    vector<size_t> scores(num_down.size(), 0);
    for (int counter = num_down.size() - 1; counter >= 0; counter--) {
      switch(type[counter]) {
      case 0:
	scores[counter] = num_down[counter];
	break;
      case 1:
	scores[counter] = 10 + num_down[counter+1];
	break;
      case 2:
	scores[counter] = 10 + num_down[counter+1] + num_down[counter+2];
	break;
      }
      total_score += scores[counter];
    }
    cout << total_score << endl;
    getline(cin, line);
  }
  return 0;
}
