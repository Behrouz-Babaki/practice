#include <iostream>
#include <string>
#include <sstream>
using namespace std;

long long int countTerms (long int , long int);

int main (void){
  string str;
  istringstream sstr;
  
  int counter = 0;
  long int initial , limit;

  getline(cin , str);
  sstr.str(str);
  sstr >> initial >> limit;

  while (cin.good() && initial > 0 && limit > 0){
    counter ++;
    
    long long int terms = countTerms (initial , limit);
    cout << "Case " << counter << ": A = " << initial 
	 << ", limit = " << limit << ", number of terms = " << terms << endl;

    getline(cin , str);

    sstr.clear();
    sstr.str(str);
    sstr >> initial >> limit;
  }

  return 0;
}

long long int countTerms(long int initial , long int limit){
  long long int count = 1;
  while (initial != 1){
    if (initial % 2 == 0)
      initial /= 2;
    else
      initial = initial * 3 + 1;
    
    if (initial > limit)
      break;

      count++;
  }
  
  return count;
}
