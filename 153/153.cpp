#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <iostream>

using std::map;
using std::cout;
using std::endl;

size_t countPre(char*, size_t, size_t);
size_t countPermutations (const map<char,size_t>&, char, char);
size_t factorial(size_t);

int main(void) {

  size_t count;
  char str[31];

  scanf("%s", str);
  while (str[0] != '#') {
    count = countPre(str, 0, strlen(str));
    printf("%10zd\n", count);
    scanf("%s", str);
  } 

  return 0;
}

size_t countPre (char* str, size_t start, size_t end) {
  // cout << "string:" << str << "\tstart:" << start << "\tend:" << end << endl;

  if (start == end-1)
    return 1;
  
  size_t count = 0;
  map <char, size_t> letterCounts;
  char first = str[start];
  for (size_t counter = start; counter < end; counter++)
    {
      char letter = str[counter];
      if (letterCounts.find(str[counter]) == letterCounts.end())
	letterCounts[letter] = 1;
      else 
	// supicious
	letterCounts[letter] ++;
    }
  
  // for (map<char,size_t>::iterator itr = letterCounts.begin(), endItr = letterCounts.end(); 
  //      itr != endItr; itr++)
  //   cout << "letter: " << itr->first << " count:" << itr->second << "\t";
  // cout << endl;

  for (map<char,size_t>::iterator itr = letterCounts.begin(), endItr = letterCounts.end(); 
       (itr->first) < first && itr != endItr; itr++)
    count += countPermutations (letterCounts, first, itr->first);

  count += countPre (str, start+1, end);
  return count;
}

size_t countPermutations (const map<char,size_t>& letterCounts, char first, char cand) {
  size_t totalCount = 0;
  for (map<char,size_t>::const_iterator itr = letterCounts.begin(), endItr = letterCounts.end();
       itr != endItr; itr++)
    totalCount += itr->second;
  totalCount --;
  size_t perms = factorial(totalCount);
  for (map<char,size_t>::const_iterator itr = letterCounts.begin(), endItr = letterCounts.end();
       itr != endItr; itr++)
    if (itr->first != cand)
      perms /= itr->second;
    else if (itr->second > 1)
      perms /= ((itr->second) - 1);

  return perms;
}

size_t factorial (size_t x) {
  return (x == 1 ? x : x*factorial(x-1));
}
