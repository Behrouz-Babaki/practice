#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::getline;
using std::map;
using std::set;

typedef map<int,bool> constraint;
typedef vector<constraint> conset;
bool verbose = false;

bool search(conset conss, vector<bool> active, int loc, vector<int>& sol);
void print_conss(conset cns, vector<bool> active);

int main(void) {
  string line;
  while(getline(cin, line)){
    conset constraints;
    while (line.front()!='.') {
      int id=0;
      map<int,bool> cons;
      while(line[id]!=';'){
	cons[line[id+1]-'A'] = (line[id]=='+') ? true : false;
	id += 2;
      }
      constraints.push_back(cons);
      getline(cin,line);
    }
    vector<bool> active(constraints.size(), true);
    if (verbose) {
      cout << "original constraints:" << endl;
      print_conss(constraints, active);
    }

    vector<int> sol(16, -1);
    if (search(constraints, active, 0, sol)) {
      cout << "Toppings: ";
      for (int i=0; i<16; i++)
	if (sol[i] == 1)
	  cout << (char)('A'+i);
      cout << endl;
    }
    else
      cout << "No pizza can satisfy these requests." << endl;
  }
    
  cout << endl;
  return 0;
}


bool search(conset conss, vector<bool> active, int loc, vector<int>& sol) {
  if (loc == 16)
    return true;
  bool all_gone = true;
  for (int i=0; all_gone && i<active.size(); i++)
    if (active[i])
      all_gone = false;
  if (all_gone)
    return true;
  if (sol[loc] >= 0)
    return search(conss, active, loc+1, sol);

  bool option = true;
  for (int cnt=0; cnt<2; cnt++, option!=option) {
    bool possible = true;
    for (int i=0; possible && i<conss.size(); i++)
      if (conss[i].size()==1 && 
	  conss[i].find(loc)!=conss[i].end() &&
	  (conss[i].find(loc)->second) != option)
	possible = false;
    if (possible) {
      if (verbose)
	cout << "making " << loc << (option ? " true" : " false") << "." << endl;
      sol[loc] = option;
      conset conss_new = conss;
      for (int i = 0; i < conss_new.size(); i++)
	if (active[i] && conss_new[i].find(loc)!=conss_new[i].end())
	  if (conss_new[i].find(loc)->second == option)
	    active[i] = false;
	  else
	    conss_new[i].erase(conss_new[i].find(loc));
      if (verbose)
	print_conss(conss_new, active);
      if (search(conss_new, active, loc+1, sol))
	return true;
    }
  }
  if (verbose)
    cout << "didn't work out for " << loc << endl;
  sol[loc] = -1;
  return false;
}

void print_conss(conset cns, vector<bool> active){
  for (int cnt = 0; cnt < cns.size(); cnt++)
    if (active[cnt]) {
      for (int i=0; i<16; i++)
	if (cns[cnt].find(i)!=cns[cnt].end()){
	  if (cns[cnt][i])
	    cout << "+";
	  else
	    cout << "-";
	  cout << (char)('A'+i);
	}
      cout << endl;
    }
}

