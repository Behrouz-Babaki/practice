#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <utility>

#include <fstream>

using namespace std;
typedef map<int,bool> constraint;
typedef vector<constraint> conset;

void print_conss(conset cns);
bool check(const conset& conss, const set<int>& sol);
int main(int argc, char* argv[]){
  ifstream f_cons;
  ifstream f_out;
  f_cons.open(argv[1], ios::out);
  f_out.open(argv[2], ios::out);
  if (f_cons.is_open() && 
      f_out.is_open()) {
    string line;
    while(getline(f_cons, line)){
      conset constraints;
      while (line.front()!='.') {
	int id=0;
	map<int,bool> cons;
	while(line[id]!=';'){
	  cons[line[id+1]-'A'] = (line[id]=='+') ? true : false;
	  id += 2;
      }
	constraints.push_back(cons);
	getline(f_cons,line);
      }
      //print_conss(constraints, active);
      getline(f_out, line);
      if (line.substr(0,2)=="No")
	cout << "OK?" << endl;
      else {
	set<int> sol;
	for (int i=10; i<line.size(); i++)
	  sol.insert(line[i]-'A');
	cout << (check(constraints, sol) ? "OK" : "FAIL") << endl;
      }
    } 
    f_cons.close();
    f_out.close();
  }
  return 0;
}

void print_conss(conset cns){
  for (int cnt = 0; cnt < cns.size(); cnt++) {
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

bool check(const conset& conss, 
	   const set<int>& sol) {
  bool sat = true;
  for (int i=0; sat && i<conss.size(); i++) {
    bool found = false;
    for (map<int,bool>::const_iterator itr=conss[i].begin(), 
	   end=conss[i].end(); itr!=end; itr++)
      if ((itr->second && sol.find(itr->first)!=sol.end()) ||
	  (!(itr->second) && sol.find(itr->first)==sol.end()))
	found = true;
    if (!found)
      sat = false;
  }
  return sat;
}
