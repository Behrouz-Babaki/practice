#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::vector;

int main(void){
  int number_of_cases;
  cin >> number_of_cases; 
  for (int counter = 0; counter < number_of_cases; counter++)
    {
      int number_of_days;
      cin >> number_of_days;
      vector<bool> days(number_of_days, true);
      
      int number_of_parties;
      cin >> number_of_parties;

      for (int i = 0; i < number_of_parties; i++){
	int parameter;
	cin >> parameter;
	for (int dayCounter = parameter; dayCounter <= number_of_days; dayCounter += parameter)
	  days[dayCounter - 1] = false;
      }
      
      int hartals = 0;
      for (int i = 0; i < number_of_days; i++)
	if ((i+1)%7 != 0 && (i+2)%7 != 0 && !days[i])
	  hartals++;
      cout << hartals << endl;

    }
  return 0;
}
