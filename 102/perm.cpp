#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
using namespace std;

int size;

void perm (char* input, int start , int end);
char* swap (char* input, int firstIndex , int secondIndex);

int main (void){
  string line;
  getline(cin , line);
  size = line.length();
  char* cstr = new char[line.length() + 1];
  strcpy(cstr , line.c_str());
  perm(cstr , 0 , size - 1);
  return 0;
}

void perm (char* input , int start , int end){
  char * input2 = new char [size];
  strcpy(input2 , input);
  if (start == end)
    cout << input << endl;
  for (int index = start ; index <= end ; index++)
    perm (swap(input2 , start , index) , start + 1 , end);
}

char* swap(char* input, int firstIndex , int secondIndex){
  char temp = input[firstIndex];
  input[firstIndex] = input [secondIndex];
  input[secondIndex] = temp;

  return input;
}
