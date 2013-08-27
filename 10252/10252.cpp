#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::string;
using std::vector;
using std::sort;

int main (void){

  string first, second;

  while (getline(cin, first)){
    getline(cin, second);

    sort(first.begin() , first.end());
    sort (second.begin(), second.end());
    
    string sub;
    
    for (string::iterator itr1 = first.begin() , itr2 = second.begin(); 
	 itr1 != first.end() && itr2 != second.end(); )
      {
	char ch1 = *itr1 , ch2 = *itr2;
	if (ch1 == ch2)
	  {
	    sub.push_back(ch1);
	    itr1 ++;
	    itr2 ++;
	  }
	
	else if (ch1 < ch2)
	  itr1 ++;

	else if (ch2 < ch1)
	  itr2 ++;
      }

    cout << sub << endl;
  }

  return 0;
}
