#include <iostream>
#include <string>
#include <vector>
#include <set>

using std::endl;
using std::cout;
using std::cin;
using std::ws;
using std::string;
using std::vector;
using std::set;

vector<vector<bool> > input;
bool led[10][7] = {
  {1,1,1,1,1,1,0},
  {0,1,1,0,0,0,0},
  {1,1,0,1,1,0,1},
  {1,1,1,1,0,0,1},
  {0,1,1,0,0,1,1},
  {1,0,1,1,0,1,1},
  {1,0,1,1,1,1,1},
  {1,1,1,0,0,0,0},
  {1,1,1,1,1,1,1},
  {1,1,1,1,0,1,1}
};

void print (void) {
  for (int i=0; i<10; i++){
    cout << "*********" << endl;
    cout << " " << (led[i][0] ? "-" : " ") << " " << endl;
    cout << (led[i][5]? "|" : " ") << " " << (led[i][1] ? "|":" ") << endl;
    cout << " " << (led[i][6] ? "-" : " ") << " " << endl;
    cout << (led[i][4]? "|" : " ") << " " << (led[i][2] ? "|":" ") << endl;
    cout << " " << (led[i][3] ? "-" : " ") << " " << endl;
  }
}

bool search(int loc, int number, set<int> faulty);
bool match(int number, const vector<bool>& rep, set<int>& faulty);

int main(void) {
  int num_lines;
  cin >> num_lines >> ws;
  while (num_lines) {
    string line;
    input.clear();
    input.resize(num_lines, vector<bool>(7));
    for (int i=0; i<num_lines; i++){
      getline(cin, line);
      for (int j=0;j<7; j++)
	input[i][j] = (line[j]=='Y');
    }
    
    bool matched = false;
    for (int i=num_lines-1; !matched && i<=9; i++) {
      set<int> faulty;
      if (match(i, input[0], faulty))
	if (search(1, i-1, faulty)) 
	  matched = true;
    }

    if (matched)
      cout << "MATCH" << endl;
    else
      cout << "MISMATCH" << endl;
    
    cin >> num_lines >> ws;
  }
  return 0;
}


bool match(int number, const vector<bool>& rep, set<int>& faulty) {
  faulty.clear();
  bool matchable = true;
  for (int i=0; matchable && i<7; i++) 
    if (rep[i] && !led[number][i])
      matchable = false;
    else if (led[number][i] && !rep[i])
      faulty.insert(i);
  return matchable;
}

bool search(int loc, int number, set<int> faulty) {
  if (loc == input.size())
    return true;
  set<int> next_fault = faulty;
  bool matchable = true;
  for (int i=0; matchable && i<7; i++) {
    if (input[loc][i] && faulty.find(i) != faulty.end())
      matchable = false;
    else if (input[loc][i] && !led[number][i])
      matchable = false;
    else if (!input[loc][i] && led[number][i])
      next_fault.insert(i);
  }
  if (!matchable)
    return false;
  else 
    return search(loc+1, number-1, next_fault);
}
