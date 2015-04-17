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

void b2d(void);
void d2b(void);
void print_d(int rbegin, int rend, int cbegin, int cend);
pair<bool,bool> all(int rbegin, int rend, int cbegin, int cend);
void fill(int rbegin, int rend, int cbegin, int cend);
void print_output(void);

int main(void) {
  char format;
  cin >> ws >> format;
  while (format!='#') {
    cin >> rows >> columns >> ws;
    string line;
    output.clear();
    table.clear();
    table.resize(rows, vector<bool>(columns));
    if (format=='B') {
      cout << 'D' << setw(4) << right << rows << setw(4) << columns << endl; 
	b2d();
	print_output();
    }
    else {
      cout << 'B' << setw(4) << right << rows << setw(4) << columns << endl;
	d2b();
	print_output();
    }
    cin >> ws >> format;
  }
  return 0;
}

void b2d(void) {
  for (int i=0; i<rows; i++)
    for (int j=0; j<columns; j++) {
      char ch;
      cin >> ws >> ch;
      table[i][j] = (ch == '1');
    }
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

void d2b(void){
  fill(0, rows-1, 0, columns-1);
  for (int i=0; i<rows; i++){
    for (int j=0; j<columns; j++){
      char ch = table[i][j] ? '1':'0';
      output.push_back(ch);
    }
  }
}

void fill(int rbegin, int rend, int cbegin, int cend){
  if (rend<rbegin || cend<cbegin)
    return;
  char ch;
  cin >> ws >> ch;
  if(ch== '0' || ch == '1') {
    for (int i=rbegin; i<=rend; i++)
      for (int j=cbegin; j<=cend; j++)
	table[i][j] = (ch == '1');
    return;
  }

  int rmid = (rbegin+rend)/2;
  int cmid = (cbegin+cend)/2;
  fill(rbegin, rmid, cbegin, cmid);
  fill(rbegin, rmid, cmid+1, cend);
  fill(rmid+1, rend, cbegin, cmid);
  fill(rmid+1, rend, cmid+1, cend);
  return;
}

void print_output(void){
  int i=0;
  for (; i<output.length(); i++) {
    cout <<output[i];
    if ((i+1)%50==0 && i<(output.length()-1))
      cout << endl;
  }
  cout << endl;
}

