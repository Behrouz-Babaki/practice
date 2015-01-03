#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>

using std::cout;
using std::endl;
using std::cin;
using std::ws;
using std::vector;
using std::string;
using std::istringstream;
using std::map;
using std::sort;

void add_letters (const string word, map<char,char>& pattern);
void print_decrypted (const vector<string>& encrypted, 
		      const map<char,char>& pattern,
		      bool success);
bool find_pattern (const vector<string>& dictionary, 
		   const vector<string>& encrypted, 
		   map<char,char>& pattern);
bool recurse (const vector<string>& dictionary, 
	      const vector<string>& encrypted, 
	      size_t position, map<char,char>& pattern);

int main(void) {
  size_t num_words;
  cin >> num_words >> ws;
  vector<string> dictionary;
  map<char,char> pattern;
  string word;
  for (size_t word_counter = 0; word_counter < num_words; word_counter++) {
    cin >> word >> ws;
    add_letters(word, pattern);
    dictionary.push_back(word);
  }
  
  string line;
  while (getline(cin, line)) {
    istringstream ss (line);
    vector<string> encrypted;
    string input_word;
    while (ss >> input_word) 
      encrypted.push_back(input_word);
    bool success = find_pattern (dictionary, encrypted, pattern);
    print_decrypted (encrypted, pattern, success);
      
  }
  return 0;
}

void add_letters (const string word, map<char,char>& pattern) {
  for (string::const_iterator itr = word.begin(), end_itr = word.end(); itr < end_itr; itr++)
    if (pattern.find(*itr) == pattern.end())
      pattern[*itr] = 0;
}

void print_decrypted (const vector<string>& encrypted, const map<char,char>& pattern, bool success) {
  map<char,char> reverse_pattern;
  for (map<char,char>::const_iterator itr = pattern.begin(), end_itr = pattern.end(); 
       itr != end_itr; itr++)
    reverse_pattern [itr->second] = itr->first;

  for (size_t word_counter = 0, size = encrypted.size(); word_counter < size; word_counter++) {
    for (string::const_iterator l_itr = encrypted[word_counter].begin(), 
	   l_itr_end = encrypted[word_counter].end(); l_itr < l_itr_end; l_itr++) 
      if (success)
	cout << reverse_pattern [*l_itr];
      else
	cout << "*";

    if (word_counter < size-1)
      cout << " ";
  }
    cout << endl;
}

bool find_pattern (const vector<string>& dictionary, 
		   const vector<string>& encrypted, 
		   map<char,char>& pattern) {
  vector<string> encrypted_sorted (encrypted);
  sort(encrypted_sorted.begin(), encrypted_sorted.end(), 
       [](const string & a, const string & b) -> bool
       { 
	 return a.size() > b.size(); 
       });

  return recurse (dictionary, encrypted_sorted, 0, pattern);
}

bool recurse (const vector<string>& dictionary, const vector<string>& encrypted, size_t position, map<char,char>& pattern) {

  if (position == encrypted.size())
    return true;

  string input_word = encrypted [position];
  vector<string> possible_matches;
  for (size_t word_counter = 0, size = dictionary.size(); word_counter < size; word_counter++)
    if (encrypted[word_counter].size() == input_word.size())
      possible_matches.push_back(encrypted[word_counter]);
  
  bool success = false;
  for (size_t match_counter = 0, size = possible_matches.size(); 
       !success && match_counter; match_counter++) {
    string current_match = possible_matches [match_counter];
    bool match_success = true;
    vector<char> matched;
    for (size_t letter_counter = 0, word_size = input_word.size(); 
	 match_success && letter_counter < word_size; letter_counter++)
      if (pattern[current_match[letter_counter]] == 0) {
	pattern[current_match[letter_counter]] = input_word[letter_counter];
	matched.push_back(current_match[letter_counter]);
      }
      else if (pattern [current_match[letter_counter]] != input_word[letter_counter])
	match_success = false;

    if (match_success && recurse(dictionary, encrypted, position + 1, pattern))
      success = true;
    else
      for (size_t letter_counter = 0, size = matched.size(); 
	   letter_counter < size; letter_counter++)
	pattern[matched[letter_counter]] = 0;
  }
  return success;
}
