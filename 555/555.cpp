#include <iostream>
#include <string>
#include <utility>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;
using std::pair;
using std::make_pair;

int main(void){

  char players[4] = {'S', 'W', 'N', 'E'};
  char colors[4] = {'C', 'D', 'S', 'H'};
  char cards[13] = {'2','3','4','5','6','7','8','9','T','J','Q','K','A'};

  map<char,int> playerMap;
  for (int counter = 0; counter < 4; counter++)
    playerMap.insert(make_pair(players[counter],counter));

  map<char,int> colorMap;
  for (int counter=0; counter < 4; counter++)
    colorMap.insert(make_pair(colors[counter],counter));

  map<char,int> cardMap;
  for (int counter=0; counter < 13; counter++)
    cardMap.insert(make_pair(cards[counter],counter));
    
  char c;
  cin >> c;
  while (c != '#') {
    string first, second;
    cin >> first >> second;
    first.append(second);

    
    cin >> c;
  }
  
  return 0;
}
