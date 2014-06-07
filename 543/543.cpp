#include <iostream>
#include <vector>

using std::endl;
using std::cout;
using std::cin;
using std::vector;

void goldbach(int);
void generatePrimes(vector<int>&);

int main(void){

  vector<int> primes;
  generatePrimes(primes);

  int n = -1;
  cin >> n;
  while (n){
    goldbach(n);
    cin >> n;
  }
  return 0;
}

void goldbach(int n){
  /**
   * test output
   * 
   */
  cout << n << " = " << n/2 << " + " << n/2 << endl;
}

void generatePrimes(vector<int>& primes){
  const int limit = 1000000;
  int a[limit];
  a[1] = 0;
  for (int counter = 2 ; counter < limit; counter+=2){
    a[counter] = 0;
    a[counter+1] = 1;
  }
    
}
