#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <cmath>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::pair;
using std::make_pair;
using std::sqrt;
using std::setprecision;
using std::fixed;

enum direction {N, NE, E, SE, S, SW, W, NW};

direction getDirection (string);
bool isLetter (char);
bool isNumber(char);
void readLine (const string, vector<pair<int,direction> >&);

int main(void) {
  string line;
  const double c = sqrt(2)/2;
  int mapNumber = 0;
  
  getline (cin, line);
  while (line.compare("END")) {
    mapNumber ++;
    vector<pair<int, direction> > vec;
    readLine (line,vec);
    double right = 0;
    double up = 0;
    for (auto p : vec) {
      int val = p.first;
      switch(p.second) {
      case N:
	up += val;
	break;
      case NE:
	up += c*val;
	right += c*val;
	break;
      case E:
	right += val;
	break;
      case SE:
	up -= c*val;
	right += c*val;
	break;
      case S:
	up -= val;
	break;
      case SW:
	up -= c *val;
	right -= c*val;
	break;
      case W:
	right -= val;
	break;
      case NW:
	right -= c*val;
	up += c*val;
	break;
      }
    }
    cout << "Map #" << mapNumber << endl;
    cout << fixed;
    cout << "The treasure is located at (" << setprecision(3) << right << "," << up << ")." << endl;
    cout << "The distance to the treasure is " << setprecision(3) << sqrt (pow(right,2) + pow(up,2)) << "." << endl;
    cout << endl;

    getline(cin, line);
  }

  return 0;
}


void readLine (const string line, vector<pair<int,direction> >& vec) {

  string::const_iterator itr = line.begin();
  int number;
  direction dir;
  string strdir;

  vec.clear();

  while (*itr != '.') {

    if (*itr == ',')
      itr ++;

    if (isLetter(*itr)) {
      strdir.clear();
      while (isLetter(*itr)) {
	strdir.append(1,*itr);
	itr ++;
      }
      dir = getDirection (strdir);
      vec.push_back(make_pair(number, dir));
    }

    if (isNumber(*itr)) {
      number = 0;
      while (isNumber(*itr)) {
	number = (number * 10) + (*itr - 48);
	itr ++;
      }
    }
  }

}

bool isNumber(char ch) {
  return (ch >= 48 && ch <= 57);
}

bool isLetter (char ch) {
  bool value = false;
  switch (ch) {
  case 'N':
  case 'E':
  case 'W':
  case 'S':
    value = true;
    break;
  default:
    value = false;
  }

  return value;
}

direction getDirection (string str) {
  if (!str.compare("N"))
    return N;
  if (!str.compare("NE"))
    return NE;
  if (!str.compare("SE"))
    return SE;
  if (!str.compare("E"))
    return E;
  if (!str.compare("S"))
    return S;
  if (!str.compare("SW"))
    return SW;
  if (!str.compare("W"))
    return W;
  if (!str.compare("NW"))
    return NW;
}
