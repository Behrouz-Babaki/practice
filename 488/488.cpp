#include<iostream>
#include<cstdlib>
using namespace std;

void printWaveForm(int,int);

int main(void)
{
  string val;
  int number_of_cases;
  getline(cin , val);
  
  number_of_cases = atoi(val.c_str());
  
  for (int counter = 0 ; counter < number_of_cases ; counter++)
    {
      if (counter != 0)
	cout << endl;
      
      getline(cin , val);
      getline(cin , val);
      
      int amplitude = atoi(val.c_str());
      getline(cin , val);
      int frequency = atoi(val.c_str());

      printWaveForm(amplitude , frequency);

    }

  return 0;
}

void printWaveForm(int amplitude , int frequency){
  for (int counter = 0 ; counter < frequency ; counter ++ )
    {

      for (int counter2 = 1 ; counter2 < amplitude ; counter2 ++){
      	for (int counter3 = 0 ; counter3 < counter2 ; counter3++)
      	  cout << counter2;
      	cout << endl;
      }
      

      for (int counter2 = amplitude ; counter2 >= 1 ; counter2 --){
      	for (int counter3 = 0 ; counter3 < counter2 ; counter3++)
      	  cout << counter2;
      	cout << endl;
      }
      
      if (counter < frequency - 1)
	cout << endl;
    }
}
