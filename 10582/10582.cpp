#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::ws;
using std::cout;
using std::endl;
using std::vector;
using std::string;

vector<vector<int> > board;

int main(void){
  int num_cases;
  cin >> num_cases;
  while (num_cases--){
    int rows, cols;
    cin >> rows >> cols >> ws;
    board.clear();
    board.resize(rows, vector<int>(cols));
    string line;
    getline(cin, line);
    for (int i=0; i<rows; i++){
      getline(cin, line);
      getline(cin, line);
      for (int j=0; j<cols; j++) {
	string cell=line.substr((j*4)+1,3);
	if (cell=="***")
	  board[i][j]=1;
	else if (cell=="** ")
	  board[i][j]=2;
	else 
	  board[i][j]=3;
      }
      getline(cin, line);
      getline(cin, line);
    }
    // for (auto i : board){
    //   for (auto j : i)
    // 	cout << j;
    //   cout << endl;
    // }
  }
  return 0;
}
