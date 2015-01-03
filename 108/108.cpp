#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int max;
int getScore(vector<vector<vector<int> > >&, vector<vector<vector<bool> > >&, const vector<vector<short> >&, size_t, size_t, size_t);

int main (void){
  size_t num;
  cin >> num;
  vector<vector<vector<int> > > scores(num, vector<vector<int> >(num, vector<int>(num, 0)));
  vector<vector<vector<bool> > > flags(num, vector<vector<bool> >(num, vector<bool>(num, false)));

  short val;
  vector<vector<short> > vec (num, vector<short>(num, 0));
  for (size_t outer = 0; outer < num; outer++)
    for (size_t inner = 0; inner < num; inner ++){
      cin >> val;
      vec[outer][inner] = val;
      if (val > max)
	max = val;
    }

  for (size_t counter1 = 0; counter1 < num; counter1++)
    for (size_t counter2 = 0; counter2 < num; counter2++)
      getScore(scores, flags, vec, counter1, counter2, num -1);

  cout << max << endl;
  return 0;
}


int getScore(vector<vector<vector<int> > >& scores, vector<vector<vector<bool> > >& flags, const vector<vector<short> >& vec, size_t row1, size_t row2, size_t col){
  int column_sum = 0;
  for (size_t counter = row1; counter <= row2; counter++)
    column_sum += vec[counter][col];

  if (col == 0)
    return column_sum;
  
  if (!flags[row1][row2][col-1]){
    scores[row1][row2][col-1] = getScore(scores, flags, vec, row1, row2, col-1);
    flags[row1][row2][col-1] = true;
  }
  int prev_sum = scores[row1][row2][col-1];
  
  if (prev_sum > 0)
    column_sum += prev_sum;

  if (column_sum > max)
    max = column_sum;
  
  scores[row1][row2][col] = column_sum;
  flags[row1][row2][col] = true;
  return column_sum;
}
