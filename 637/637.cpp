#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main(void) {
  size_t num_pages;
  cin >> num_pages;
  while (num_pages) {
    size_t num_sheets = (num_pages + 3)/4;
    vector<vector<size_t> > prints (num_sheets+1, vector<size_t> (4,0));
    size_t content = 1;
    for (size_t counter = 1; counter <= num_sheets; counter++){
      prints[counter][0] = content++;
      if (content <= num_pages)
	prints[counter][1] = content++;
    }

    for (size_t sheet_counter = num_sheets; sheet_counter >0; sheet_counter--) {
      if (content <= num_pages)
	prints[sheet_counter][2] = content++;
      if (content <= num_pages)
	prints[sheet_counter][3] = content++;
    }
    cout << "Printing order for " << num_pages << " pages:" << endl;
    for (size_t counter = 1; counter <= num_sheets; counter++) {
      if (prints[counter][0] || prints[counter][3]) {
	cout << "Sheet " << counter << ", front: ";
	if (prints[counter][3])
	  cout << prints[counter][3];
	else 
	  cout << "Blank";
	cout << ", ";
	if (prints[counter][0])
	  cout << prints[counter][0];
	else 
	  cout << "Blank";
	cout << endl;
      }
      //TODO: Check if this test is necessary.
      if (prints[counter][1] || prints[counter][2]) {
	cout << "Sheet " << counter << ", back : ";
	if (prints[counter][1])
	  cout << prints[counter][1];
	else 
	  cout << "Blank";
	cout << ", ";
	if (prints[counter][2])
	  cout << prints[counter][2];
	else 
	  cout << "Blank";
	cout << endl;
      }
    }
    cin >> num_pages;
  }
  return 0;
}
