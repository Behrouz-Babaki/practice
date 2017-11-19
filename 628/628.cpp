#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::endl;
using std::cout;
using std::vector;
using std::string;
using std::to_string;

void print_vector(const vector<string>&);
void print_password(const vector<string>& words, string rule, vector<string>& password, int pos);

int main(void) {
  int num_words;
  int num_rules;
  while (cin >> num_words) {
    vector<string> words(num_words);
    for (int i=0; i<num_words; i++)
      cin >> words[i];
    cout << "--" << endl;
    cin >> num_rules;
    string rule;
    for (int i=0; i<num_rules; i++) {
      cin >> rule;
      vector<string> password;
      print_password(words, rule, password, 0);
    }

  }
  return 0;
}

void print_password(const vector<string>& words, string rule, vector<string>& password, int pos) {
  if(pos == rule.size()) {
    for (auto p : password)
      cout << p;
    cout << endl;
    return;
  }

  if(rule[pos] == '#')
    for(auto word : words) {
      password.push_back(word);
      print_password(words, rule, password, pos+1);
      password.pop_back();
    }

  else
    for (int i=0; i<10; i++) {
      password.push_back(to_string(i));
      print_password(words, rule, password, pos+1);
      password.pop_back();
    }
}

void print_vector(const vector<string>& v) {
  for (auto w : v)
    cout << w << "\t";
  cout << endl;
}
