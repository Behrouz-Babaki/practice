#include <iostream>
#include <iomanip>
#include <string>
#include <utility>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::ws;
using std::setw;
using std::right;
using std::left;
using std::string;
using std::pair;
using std::make_pair;
using std::vector;

int rows, columns;
vector<vector<bool> > table;
string output;

void b2d(string& line);
void d2b(string& line);
void print_d(int rbegin, int rend, int cbegin, int cend);
pair<bool,bool> all(int rbegin, int rend, int cbegin, int cend);
int fill(string& line, int loc, int rbegin, int rend, int cbegin, int cend);

int main(void) {
  char format;
  cin >> format;
  while (format!='#') {
    cin >> rows >> columns >> ws;
    output.clear();
    table.clear();
    table.resize(rows, vector<bool>(columns));
    string line;
    getline(cin, line);
    if (format=='B') {
      b2d(line);
      cout << 'D' << setw(4) << right << rows << setw(4) << columns << endl; 
      cout << setw(50) << left << output << endl;
    }
    else {
      d2b(line);
      cout << 'B' << setw(4) << right << rows << setw(4) << columns << endl;
      cout << setw(50) << left << output << endl;
    }
    cin >> format;
  }
  return 0;
}

void b2d(string& line) {
  int idx = 0;
  for (int i=0; i<rows; i++)
    for (int j=0; j<columns; j++)
      table[i][j] = (line[idx++] == '1');
  print_d(0, rows-1, 0, columns-1);
}

void print_d(int rbegin, int rend, int cbegin, int cend){
  if (rend<rbegin || cend<cbegin)
    return;
  pair<bool,bool> res = all(rbegin, rend, cbegin, cend);
  if (res.first)
    output.push_back('1');
  else if (res.second) 
    output.push_back('0');
  else {
    output.push_back('D');
    int rmid = (rbegin+rend)/2;
    int cmid = (cbegin+cend)/2;
    print_d(rbegin, rmid, cbegin, cmid);
    print_d(rbegin, rmid, cmid+1, cend);
    print_d(rmid+1, rend, cbegin, cmid);
    print_d(rmid+1, rend, cmid+1, cend);
  }
}

pair<bool,bool> all(int rbegin, int rend, int cbegin, int cend){
  bool zero = true;
  bool one = true;
  for (int row=rbegin; (zero||one) && row<=rend; row++)
    for (int col=cbegin; (zero||one) && col<=cend; col++) 
      if (table[row][col])
	zero = false;
      else
	one = false;
  return make_pair(one, zero);
}

void d2b(string& line){
  fill(line, 0, 0, rows-1, 0, columns-1);
  for (int i=0; i<rows; i++){
    for (int j=0; j<columns; j++){
      char ch = table[i][j] ? '1':'0';
      output.push_back(ch);
    }
  }
}

int fill(string& line, int loc, int rbegin, int rend, int cbegin, int cend){
  if (rend<rbegin || cend<cbegin)
    return loc;

  if(line[loc] == '0' || line[loc] == '1') {
    for (int i=rbegin; i<=rend; i++)
      for (int j=cbegin; j<=cend; j++)
	table[i][j] = (line[loc] == '1');
    return loc+1;
  }

  int rmid = (rbegin+rend)/2;
  int cmid = (cbegin+cend)/2;
  loc = fill(line, loc+1,  rbegin, rmid, cbegin, cmid);
  loc = fill(line, loc, rbegin, rmid, cmid+1, cend);
  loc = fill(line, loc, rmid+1, rend, cbegin, cmid);
  loc = fill(line, loc, rmid+1, rend, cmid+1, cend);
  return loc;
}

/*
  cout << 'D' << setw(4) << right << 3 << setw(4) << 4 << endl;
  cout << setw(50) << left << "D0D1001D101" << endl;
*/
