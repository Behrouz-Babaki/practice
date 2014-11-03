#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;
using std::vector;
using std::ws;

char orientations[4] = {'N', 'O', 'S', 'L'};

int main(void) {
   size_t N, M, S;
   cin >> N >> M >> S >> ws;
  while (N > 0) {
    size_t xpos, ypos, orientation;
    vector<vector<int> > arena (N, vector<int> (M));
    size_t collected = 0;
    string line;
    for (size_t row_counter = 0; row_counter < N; row_counter++){
      getline(cin, line);
      for (size_t col_counter = 0; col_counter < M; col_counter++)
  	switch(line.at(col_counter)) {
  	case '.':
  	  arena[row_counter][col_counter] = 0;
  	  break;
  	case '*':
  	  arena[row_counter][col_counter] = 1;
  	  break;
  	case '#':
  	  arena[row_counter][col_counter] = -1;
  	  break;
  	case 'N':
  	  ypos = row_counter;
  	  xpos = col_counter;
  	  orientation = 0;
  	  break;
  	case'O':
  	  ypos = row_counter;
  	  xpos = col_counter;
  	  orientation = 1;
  	  break;
  	case 'S':
  	  ypos = row_counter;
	  xpos = col_counter;
  	  orientation = 2;
  	  break;
  	case 'L':
  	  ypos = row_counter;
  	  xpos = col_counter;
  	  orientation = 3;
  	  break;
  	}
    }

    size_t nextx, nexty;
    getline(cin, line);
    for (size_t instruction_cnt = 0; instruction_cnt < S; instruction_cnt++) 
      switch(line.at(instruction_cnt)) {
      case 'D':
	orientation = (orientation - 1 + 4) % 4;
  	break;
      case 'E':
	orientation = (orientation + 1) % 4;
  	break;
      case 'F':
	nextx = xpos;
	nexty = ypos;
	switch(orientation){
	case 0:
	  nexty = ypos -1;
	  break;
	case 1:
	  nextx = xpos - 1;
	  break;
	case 2:
	  nexty = ypos + 1;
	  break;
	case 3:
	  nextx = xpos + 1;
	  break;
	}
	if (nextx >= 0 &&
	    nextx < M &&
	    nexty >= 0 &&
	    nexty < N && 
	    arena[nexty][nextx] >= 0){
	  xpos = nextx;
	  ypos = nexty;
	  if (arena[ypos][xpos] == 1){
	    collected++;
	    arena[ypos][xpos] = 0;
	  }
	}
  	break;
      }
    
    cout << collected << endl;
    cin >> N >> M >> S >> ws;
  }
  return 0;
}
