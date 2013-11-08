#include <iostream>
#include <string>
#include <vector>
#include <utility>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::pair;

void convertToVec(const string&, vector<unsigned int>&);

int main(void){
  string firstline;
  string secondline;
  while (getline(cin, firstline)){
    getline(cin, secondline);
    vector<unsigned int> first, second;
    convertToVec(firstline, first);
    convertToVec(secondline, second);
    
    vector<vector<unsigned int> > parts;
    int counter = 0;
    for (vector<unsigned int>::reverse_iterator itr2 = second.rbegin(), endItr2 = second.rend(); itr2 != endItr2; itr2++, counter++){

      unsigned int carry = 0;
      vector<unsigned int> current;

      for (int zeroCounter = 0; zeroCounter < counter; zeroCounter++)
	current.push_back(0);

      for(vector<unsigned int>::reverse_iterator itr1 = first.rbegin(), endItr1 = first.rend(); itr1 != endItr1; itr1++){
	unsigned int mult = (*itr2) * (*itr1) + carry;
	carry = mult / 10;
	current.push_back(mult%10);
      }

      while (carry > 0){
	current.push_back(carry%10);
	carry /= 10;
      }
      parts.push_back(current);
    }

    vector<unsigned int> sum;
    vector<pair<vector<unsigned int>::iterator, vector<unsigned int>::iterator> > itrVec;
    for (vector<vector<unsigned int> >::iterator itr = parts.begin(), endItr = parts.end(); itr != endItr; itr++)
      itrVec.push_back(make_pair(itr-> begin(), itr-> end()));
    
    unsigned int total = 0; 
    unsigned int crr = 0;
    bool cont = true;
    while (cont){
      cont = false;
      total = crr;
      
    for (int vecCounter = 0, vecSize = parts.size(); vecCounter < vecSize; vecCounter++)
      if (itrVec[vecCounter].first != itrVec[vecCounter].second){
        cont = true;
        total += *(itrVec[vecCounter].first);
        itrVec[vecCounter].first ++;
      }
    
    if (cont){
      sum.push_back(total % 10);
      crr = total / 10;
    }
    
    }
    
    
    while (crr > 0)
      {
	sum.push_back(crr%10);
	crr /= 10;
      }

    while (sum.size() > 1 && sum.back() == 0)
       sum.pop_back();
    
    for (vector<unsigned int>::reverse_iterator sumItr = sum.rbegin(), sumEndItr = sum.rend(); sumItr != sumEndItr; sumItr ++)
      cout << *sumItr;
    cout << endl;
    
  }

  return 0;
}

void convertToVec(const string& str, vector<unsigned int>& vec){
  vec.clear();
  for (string::const_iterator itr = str.begin(), endItr = str.end(); itr != endItr; itr++){
    int ch = (*itr);
    if (ch >= 48 && ch <= 57)
      vec.push_back(ch - 48);
  }
}
