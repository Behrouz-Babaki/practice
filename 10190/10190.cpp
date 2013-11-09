#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::vector;

int main(void){
  unsigned int first, second;
  while (cin >> first){
    cin >> second;
    vector<unsigned int> list;

    bool flag = true;
    if (first == 0 || second == 0)
      flag = false;

    if (first == 1 || second == 1)
      flag = false;

    if (flag && first % second != 0)
      flag = false;

    while (flag && first > 1){
      list.push_back(first);

      if (first % second != 0)
        flag = false;

      first /= second;

      if (first >= list.back())
        flag = false;
    }

    if (flag == false)
      cout << "Boring!" << endl;
    else{
      list.push_back(first);
      for (int counter = 0, size = list.size(); counter < size; counter++)
        cout << list[counter] << (counter < (size - 1) ? " " : "\n");
    }
    
  }
  return 0;
}
