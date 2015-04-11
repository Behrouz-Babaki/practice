#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int min_switch;

void switch_light(vector<vector<bool> >& lights, int row, int col);
void search(vector<vector<bool> >& lights, int row, int switch_cnt);

int main(void) {
  string line;
  cin >> line;
  while (line!="end"){
    min_switch = 101;
    string name = line;
    vector<vector<bool> > lights(10, vector<bool>(10,true));
    for (int i=0; i<10; i++){
      cin >> line;
      for (int j=0; j<10; j++)
	if (line[j]=='#')
	  lights[i][j]=false;
    }
    int mask=0;
    while(mask < (1<<10)) {
      vector<vector<bool>> lights_copy = lights;
      int switch_cnt=0;
      for (int i=0; i<10; i++)
	if (mask&(1<<i)) {
	  switch_light(lights_copy, 0, i);
	  switch_cnt++;
	}
      search(lights_copy, 1, switch_cnt);
      mask++;
    }
    cout << name << " ";
    if (min_switch > 100)
      cout << -1;
    else
      cout << min_switch;
    cout << endl;
    cin >> line;
  }
  return 0;
}

void search(vector<vector<bool> >& lights, int row, int switch_cnt) {
  if (row==10) {
    bool fail = false;
    for (int i=0; !fail && i<10; i++)
      if (lights[9][i])
	fail = true;
    if (!fail && switch_cnt < min_switch)
	min_switch = switch_cnt;
    return;
  }
  if (switch_cnt > min_switch) 
    return;

  vector<vector<bool> > lights_copy=lights;
  for (int i=0; i<10; i++)
    if (lights_copy[row-1][i]) {
      switch_light(lights_copy, row, i);
      switch_cnt++;
    }
  search(lights_copy, row+1, switch_cnt);
}

void switch_light(vector<vector<bool> >& lights, int row, int col){
  lights[row][col]=!lights[row][col];
  if (row > 0)
    lights[row-1][col]=!lights[row-1][col];
  if (row < 9)
    lights[row+1][col]=!lights[row+1][col];
  if (col>0)
    lights[row][col-1]=!lights[row][col-1];
  if (col<9)
    lights[row][col+1]=!lights[row][col+1];
}
