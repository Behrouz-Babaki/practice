#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <iostream>
#include <vector>

using std::map;
using std::cout;
using std::endl;
using std::vector;

size_t countPre(char*, size_t, size_t);
size_t countPermutations (const map<char,size_t>&, char, char);
size_t calcPerms (const vector<size_t>&, const vector<size_t>&);
size_t factorial(size_t);

int main(void) {

  size_t count;
  char str[31];

  scanf("%s", str);
  while (str[0] != '#') {
    count = countPre(str, 0, strlen(str));
    printf("%10zd\n", count + 1);
    scanf("%s", str);
  } 

  return 0;
}

size_t countPre (char* str, size_t start, size_t end) {

  if (start == end-1)
    return 0;
  
  size_t  count = 0;
  map <char, size_t> letterCounts;
  char first = str[start];
  for (size_t counter = start; counter < end; counter++)
    {
      char letter = str[counter];
      if (letterCounts.find(str[counter]) == letterCounts.end())
	letterCounts[letter] = 1;
      else 
	letterCounts[letter] ++;
    }
  
  for (map<char,size_t>::iterator itr = letterCounts.begin(), endItr = letterCounts.end(); 
       (itr->first) < first && itr != endItr; itr++)
    count += countPermutations (letterCounts, first, itr->first);

  count += countPre (str, start+1, end);
  return count;
}

size_t countPermutations (const map<char,size_t>& letterCounts, char first, char cand) {
  
  vector<size_t> total;
  vector<size_t> parts;

  size_t totalCount = 0;
  for (map<char,size_t>::const_iterator itr = letterCounts.begin(), endItr = letterCounts.end();
       itr != endItr; itr++)
    totalCount += itr->second;
  totalCount --;

  for (size_t counter = totalCount; counter > 1; counter--)
    total.push_back(counter);

  for (map<char,size_t>::const_iterator itr = letterCounts.begin(), endItr = letterCounts.end();
       itr != endItr; itr++)
    if (itr->first != cand) {
      for (size_t counter = itr->second; counter > 1; counter--)
	parts.push_back(counter);
    }
    else {
      for (size_t counter = (itr->second) - 1; counter > 1; counter--)
	parts.push_back(counter);
    }

  return calcPerms(total, parts);
}

size_t factorial (size_t x) {
  return ((x == 1 || x == 0) ? 1 : x*factorial(x-1));
}

size_t calcPerms (const vector<size_t>& total, const vector<size_t>& parts) {

  vector<size_t>::const_iterator itr = parts.begin(), endItr = parts.end();
  size_t count = 1;
  for (vector<size_t>::const_iterator totalItr = total.begin(), totalEnd = total.end();
       totalItr != totalEnd; totalItr++) {
    count *= (*totalItr);
    while (itr != endItr && count % (*itr) == 0) {
      count /= *itr;
      itr++;
    }
  }

  return count;
}
