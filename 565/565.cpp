#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::getline;

vector<vector<int> >constraints;
bool search(int loc, vector<int>& sol);

int main(void) {
  string line;
  while(getline(cin, line)){
    constraints.clear();
    while (line.front()!='.') {
      int id=0;
      vector<int> cons(16,-1);
      while(line[id]!=';'){
	cons[line[id+1]-'A'] = (line[id]=='+') ? 1 : 0;
	id += 2;
      }
      constraints.push_back(cons);
      getline(cin,line);
    }
    vector<int> sol(16, -1);
    if (search(0, sol)) {
      cout << "Toppings: ";
      for (int i=0; i<16; i++)
	if (sol[i] == 1)
	  cout << 'A'+sol[i];
      cout << endl;
    }
    else
      cout << "No pizza can satisfy these requests." << endl;
  }
    
  cout << endl;
  return 0;
}


bool search(int loc, vector<int>& sol) {
  if (loc == 16)
    return true;
  if (sol[loc] >= 0)
    return search(loc+1, sol);
//TODO implement this
  return false;
}
