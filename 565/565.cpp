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

bool search(conset conss, int loc, vector<int>& sol);
void print_conss(conset cns);

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
    vector<int> sol(16, -1);
    if (search(constraints, 0, sol)) {
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


bool search(conset conss, int loc, vector<int>& sol) {
  if (loc == 16)
    return true;
  if (sol[loc] >= 0)
    return search(conss, loc+1, sol);
  bool possible;
  //option1: sol[loc]=true
  possible = true;
  for (conset::iterator itr = conss.begin(), end = conss.end();
       possible && itr!=end; itr++)
    if (itr->size()==1 && 
	itr->find(loc)!=itr->end() &&
	!(itr->find(loc)->second))
      possible = false;
  if (possible) {
    sol[loc] = true;
    conset conss_new = conss;
    for (conset::iterator itr = conss_new.begin(), end = conss_new.end();
	 itr!=end; itr++) {
      if (itr->find(loc)!=itr->end())
	if (itr->find(loc)->second)
	  conss_new.erase(itr);
	else
	  itr->erase(itr->find(loc));
    }
    if (search(conss_new, loc+1, sol))
      return true;
  }
  //TODO do this in a loop instead of copying
  //option1: sol[loc]=false
  possible = true;
  for (conset::iterator itr = conss.begin(), end = conss.end();
       possible && itr!=end; itr++)
    if (itr->size()==1 && 
	itr->find(loc)!=itr->end() &&
	itr->find(loc)->second)
      possible = false;
  if (possible) {
    sol[loc] = false;
    conset conss_new = conss;
    for (conset::iterator itr = conss_new.begin(), end = conss_new.end();
	 itr!=end; itr++) {
      if (itr->find(loc)!=itr->end())
	if (!(itr->find(loc)->second))
	  conss_new.erase(itr);
	else
	  itr->erase(itr->find(loc));
    }
    if (search(conss_new, loc+1, sol))
      return true;
  }

  sol[loc] = -1;
  return false;
}

void print_conss(conset cns){
  for (auto c : cns) {
    for (int i=0; i<16; i++)
      if (c.find(i)!=c.end()){
	if (c[i])
	  cout << "+";
	else
	  cout << "-";
	cout << (char)('A'+i);
      }
    cout << endl;
  }
}
