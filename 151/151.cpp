#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::cin;
using std::endl;

int main (void)
{
  int N;
  cin >> N;
 while (N != 0){
   bool success = false;
   for (int m = 1; ! success && m < 11; m++){
     vector<bool> vec (N, false);
     int index = 0, counter = 0;
     while (index != 12){
       vec[index] = true;
       counter++; 
       int steps = 0;
       while (steps < m)
	 {
	   do {
	     index = (index + 1) % N;
	   }while (vec[index] == true);

	   steps ++;
	 }
     }
     if (counter == N - 1){
       success = true;
       cout << m << endl;
     }
   }
    cin >> N;
  }

  return 0;
}
