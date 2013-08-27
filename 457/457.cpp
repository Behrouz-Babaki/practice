#include <iostream>
#include <string>
#include <sstream>
using namespace std;

void printContent(int);

int main(void)
{
  string str;
  istringstream sstr;
  
  getline(cin , str);
  sstr.str(str);
  
  int dna[10];
  for (int counter = 0 ; counter < 10 ; counter ++)
    sstr >> dna[counter];
  
  
  int dishes[42];
  //todo: remove extra indices
  int temp[42];

  for (int counter = 0 ; counter < 42 ; counter++)
    temp[counter] = 0;
  
  temp[19] = 1;
  dishes[0] = 0;
  dishes[41] = 0;

  for (int counter = 0 ; counter < 50 ; counter++){

    //Todo: smart indexing
    for (int index = 1 ; index < 41 ; index ++){
      dishes[index] = temp[index];
      printContent(dishes[index]);
    }

    for (int index = 1 ; index < 41 ; index ++)
      temp[index] = dna[dishes[index - 1] + dishes[index] + dishes[index + 1]];

    cout << endl;
  }


  
  return 0;
}

void printContent(int value){
  if (value == 0)
    cout << ' ';
  else if (value == 1)
    cout << '.';
  else if (value == 2)
    cout << 'x';
  else if (value == 3)
    cout << 'w';
}
