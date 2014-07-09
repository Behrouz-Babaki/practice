#include <iostream>
#include <string>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;
using std::pair;
using std::make_pair;
using std::vector;
using std::sort;

typedef pair<int,int> card;

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

    vector<vector<card> > suits(4);
    int pInd = playerMap.at(c);

    for (int counter=0; counter<52; counter++){
      pInd = (pInd + 1) % 4;
      int color = colorMap.at(first.at(counter*2));
      int card = cardMap.at(first.at(counter*2+1));
      suits[pInd].push_back(make_pair(color,card));
    }
    
    for (int counter=0; counter<4; counter++){
      sort(suits[counter].begin(), suits[counter].end(),
	   [](const card& left, const card& right){
	       if (left.first == right.first)
		 return left.second < right.second;
	       return left.first < right.first;
	     });
      cout << players[counter] << ": ";
      for (auto x:suits[counter]){
	cout << colors[x.first] << cards[x.second];
	if (x != suits[counter].back())
	  cout << " ";
      }
      cout << endl;
    }

    cin >> c;
  }
  
  return 0;
}
