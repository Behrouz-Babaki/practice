#include <iostream>
#include <map>
#include <string>

using std::cout;
using std::cin;
using std::ws;
using std::endl;
using std::map;
using std::string;
using std::getline;

int main(void) {
  size_t number_of_cases;
  cin >> number_of_cases;
  for (size_t case_cnt = 0; case_cnt < number_of_cases; case_cnt++) {
    map<char,size_t> val_map;
    size_t num_char_lines;
    cin >> num_char_lines;
    /* improvement: input characters explicitly */
    for (size_t char_cnt = 0; char_cnt < num_char_lines; char_cnt++) {
      char ch;
      cin >> ch;
      size_t val;
      cin >> val;
      val_map[ch] = val;
    }
    
    size_t dollars, cents;
    cents = 0;
    size_t num_text_lines;
    cin >> num_text_lines >> ws;
    for (size_t txt_line_cnt = 0; txt_line_cnt < num_text_lines; txt_line_cnt++) {
      string line;
      getline(cin, line);
      for (size_t char_cnt = 0, length = line.size(); char_cnt < length; char_cnt++)
	if (val_map.find(line.at(char_cnt)) != val_map.end())
	  cents += val_map[line.at(char_cnt)];
    }

    dollars = cents / 100;
    cents = cents % 100;
    cout << dollars << ".";
    if (cents < 10)
      cout << "0";
    cout << cents << "$" << endl;
  }
  return 0;
}
