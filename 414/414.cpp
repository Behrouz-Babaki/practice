#include<iostream>
#include<string>
using namespace std;

int countSpaces(string);

int main (void)
{
  string str;

  int lines;
  cin >> lines;
  while (lines > 0){
    getline(cin , str);

    getline(cin , str);
    int total_voids = countSpaces(str);
    int min_displace = total_voids;

    for (int counter = 1 ; counter < lines ; counter++ )
      {
	getline(cin , str);
	int displace = countSpaces(str);
	total_voids += displace;
  
	if (displace < min_displace)
	  min_displace = displace;
      }
  
    cout << total_voids - (lines * min_displace) << endl;
  
    cin >> lines;
  }
  
}

int countSpaces(string str){
  int count = 0;
  string::iterator itr = str.begin();
  for (; *itr == 'X' ; itr++);
  
  for (; *itr == ' ' ; itr++)
    count++;
  
  return count;
}
