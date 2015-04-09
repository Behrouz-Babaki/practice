#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <string>

using std::endl;
using std::cin;
using std::ws;
using std::cout;
using std::map;
using std::vector;
using std::istringstream;
using std::getline;
using std::string;

struct _forward_ {
  int time;
  int duration;
  int target;
};
typedef struct _forward_ forward;
map<int, vector<forward> > m;


int find(int original, int time, int extension);
void print(int num);

int main(void) {
  int num_cases;
  cin >> num_cases >> ws;
  cout << "CALL FORWARDING OUTPUT" << endl;
  for (int case_counter=1; case_counter<=num_cases; case_counter++){
  }
  cout << "END OF OUTPUT" << endl;
  return 0;
}


int find(int original, int time, int extension) {
  if (extension == original)
    return 9999;
  if (m.find(extension)!=m.end())
    for (auto forward : m[extension]) 
      if (time >= forward.time && time <= forward.time+forward.duration) 
	if (original == 9999)
	  return find(extension, time, forward.target);
	else
	  return find(original, time, forward.target);
  return extension;
}

void print(int num) {
  int copy = num;
  int count = 0;
  while (copy){
    copy/=10;
    count++;
  }
  for(int i=0; i<4-count; i++)
    cout << "0";
  cout << num;
}
