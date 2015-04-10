#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <utility>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::getline;
using std::map;
using std::set;
using std::pair;
using std::make_pair;

typedef map<int,bool> constraint;
typedef vector<constraint> conset;
bool verbose = false;

bool search(conset conss, vector<bool> active, int loc, vector<int>& sol);
void print_conss(conset cns, vector<bool> active);
bool check_possible(const conset& conss, const vector<bool>& active, int loc, bool option);
void make_option(conset& conss, vector<bool>& active, int loc, bool option);
pair<int,bool> find_unit(const conset& conss, const vector<bool>& active);
void print_topping(const vector<int>& sol);

int main(void) {
  string line;
  while(getline(cin, line)){
    conset constraints;
    bool unsat = false;
    while (line.front()!='.') {
      int id=0;
      map<int,bool> cons;
      while(line[id]!=';'){
	cons[line[id+1]-'A'] = (line[id]=='+') ? true : false;
	id += 2;
      }
      if (cons.empty())
	unsat = true;

      constraints.push_back(cons);
      getline(cin,line);
    }
    vector<bool> active(constraints.size(), true);
    if (verbose) {
      cout << "original constraints:" << endl;
      print_conss(constraints, active);
    }

    vector<int> sol(16, -1);
    if (unsat || !search(constraints, active, 0, sol)) 
      cout << "No pizza can satisfy these requests." << endl;
  }
  return 0;
}


bool search(conset conss, vector<bool> active, int loc, vector<int>& sol) {
  if (loc == 16) {
    print_topping(sol);
    return true;
  }

  bool all_gone = true;
  for (int i=0; all_gone && i<active.size(); i++)
    if (active[i])
      all_gone = false;
  if (all_gone) {
    print_topping(sol);
    return true;
  }

  if (sol[loc] >= 0)
    return search(conss, active, loc+1, sol);

  bool option = false;
  for (int cnt=0; cnt<2; cnt++, option!=option) {
    if (check_possible(conss, active, loc, option)) {
      if (verbose)
	cout << "making " << loc << "=" << sol[loc] << " " << (option ? " true" : " false") << "." << endl;

      conset conss_new = conss;
      vector<bool> active_new = active;
      vector<int> sol_new = sol;

      sol_new[loc] = option;
      make_option(conss_new, active_new, loc, option);

      // unit resolution here
      bool unit_ok = true;
      pair<int,bool> unit = find_unit(conss_new, active_new);
      while (unit_ok && unit.first > 0) {
	if (!check_possible(conss_new, active_new, unit.first, unit.second)) {
	  if (verbose)
	    cout << "unit resolution failed" << endl;
	  unit_ok = false;
	}
	else {
	  sol_new[unit.first] = (int) unit.second;
	  make_option(conss_new, active_new, unit.first, unit.second);
	  unit = find_unit(conss_new, active_new);
	}
      }

      if (verbose)
	print_conss(conss_new, active_new);
      if (unit_ok && search(conss_new, active_new, loc+1, sol_new))
	return true;
    }
  }
  if (verbose)
    cout << "didn't work out for " << loc << endl;
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

bool check_possible(const conset& conss, const vector<bool>& active, int loc, bool option) {
    bool possible = true;
    for (int i=0; possible && i<conss.size(); i++)
      if (active[i] &&
	  conss[i].size()==1 && 
	  conss[i].find(loc)!=conss[i].end() &&
	  (conss[i].find(loc)->second) != option)
	possible = false;
    return possible;
}

void make_option(conset& conss, vector<bool>& active, int loc, bool option) {
      for (int i = 0; i < conss.size(); i++)
	if (active[i] && conss[i].find(loc)!=conss[i].end())
	  if (conss[i].find(loc)->second == option)
	    active[i] = false;
	  else
	    conss[i].erase(conss[i].find(loc));
}

pair<int,bool> find_unit(const conset& conss, const vector<bool>& active){
  bool found = false;
  pair<int,bool> result = make_pair(-1,false);
  for (int i=0; !found && i<conss.size(); i++)
    if (active[i] && conss[i].size()==1) {
      result = make_pair(conss[i].begin()->first, conss[i].begin()->second);
      found = true;
    }
  return result;
}

void print_topping(const vector<int>& sol){
    cout << "Toppings: ";
    for (int i=0; i<16; i++)
      if (sol[i] == 1)
	cout << (char)('A'+i);
    cout << endl;
}
