#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;
using std::set;
using std::map;

int get_val(char, map<char,int>&);

int main(void) {

  int num_slept;

  while(cin >> num_slept) {
    vector<bool> slept(num_slept, true);
    int num_connections;
    cin >> num_connections;
    string direct;
    cin >> direct;
    //cout << direct << endl;

    map<char,int> charmap;
    for (auto ch : direct)
      slept[get_val(ch, charmap)] = false;
    
    vector<set<int> > connections(num_slept);
    for (int i=0; i<num_connections; i++) {
      string connection;
      cin >> connection;
      int first = get_val(connection[0], charmap);
      int second = get_val(connection[1], charmap);
      if (first >= connections.size()) {
	set<int> s;
	connections.push_back(s);
	slept.push_back(false);
      }
      if (second >= connections.size()) {
	set<int> s;
	connections.push_back(s);
	slept.push_back(false);
      }
      if (connections[first].find(second) == connections[first].end())
	connections[first].insert(second);
      if (connections[second].find(first) == connections[second].end())
	connections[second].insert(first);
    }


    int y = 0;
    bool finite = true;
    num_slept -= 3;
    while (finite && (num_slept > 0)) {
      vector<int> mark;
      for (int i=0, s=slept.size(); i<s; i++)
	if (slept[i]) {
	  int neighbours = 0;
	  // break the loop earlier
	  for (auto n : connections[i]) {
	    if (!slept[n])
	      neighbours++;
	  }
	  if (neighbours >= 3){
	    mark.push_back(i);
	    num_slept--;
	  }
	}
      for (auto i : mark)
	slept[i] = false;
      finite = (mark.size());
      y++;
    }
    
    if (finite)
      cout << "WAKE UP IN, " << y << ", YEARS" << endl;
    else
      cout << "THIS BRAIN NEVER WAKES UP" << endl;
  }
  
}

int get_val(char ch, map<char,int>& m) {
  map<char,int>::iterator itr = m.find(ch);
  if (itr!=m.end())
    return itr->second;
  int s = m.size();
  m[ch] = s;
  return s;
}
