#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>

using std::cout;
using std::endl;
using std::cin;
using std::ws;
using std::vector;
using std::string;
using std::istringstream;
using std::map;

void add_letters (const string word, map<char,char>& pattern);
void print_decrypted (const vector<string>& encrypted, const map<char,char>& pattern);
void find_pattern (const vector<string>& dictionary, 
		   const vector<string>& encrypted, 
		   map<char,char>& pattern);

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
    find_pattern (dictionary, encrypted, pattern);
    print_decrypted (encrypted, pattern);
      
  }
  return 0;
}

void add_letters (const string word, map<char,char>& pattern) {
  for (string::const_iterator itr = word.begin(), end_itr = word.end(); itr < end_itr; itr++)
    if (pattern.find(*itr) == pattern.end())
      pattern[*itr] = 0;
}

void print_decrypted (const vector<string>& encrypted, const map<char,char>& pattern) {
  map<char,char> reverse_pattern;
  for (map<char,char>::const_iterator itr = pattern.begin(), end_itr = pattern.end(); 
       itr != end_itr; itr++)
    reverse_pattern [itr->second] = itr->first;

  for (size_t word_counter = 0, size = encrypted.size(); word_counter < size; word_counter++) {
    for (string::const_iterator l_itr = encrypted[word_counter].begin(), 
	   l_itr_end = encrypted[word_counter].end(); l_itr < l_itr_end; l_itr++)
	cout << reverse_pattern [*l_itr];

    if (word_counter < size-1)
      cout << " ";
  }
    cout << endl;
}

void find_pattern (const vector<string>& dictionary, 
		   const vector<string>& encrypted, 
		   map<char,char>& pattern) {

}
