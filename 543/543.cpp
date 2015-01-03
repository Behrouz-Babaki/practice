#include <iostream>
#include <vector>
#include <set>

using std::endl;
using std::cout;
using std::cin;
using std::vector;
using std::set;

void goldbach(int);
void generatePrimes();

set<int> primes;

int main(void){

  generatePrimes();

  int n = -1;
  cin >> n;
  while (n){
    goldbach(n);
    cin >> n;
  }
  return 0;
}

void goldbach(int n){
  for (auto x:primes)
    if (primes.find(n-x) != primes.end()){
      cout << n << " = " << x << " + " << n-x << endl;
      return;
    }
  cout << "Goldbach's conjecture is wrong." << endl;
}

void generatePrimes() {
  const int limit = 1000000;
  vector<bool> nums(limit+1, true);
  nums[1] = false;
  for (int counter = 2; counter <= limit; counter++)
    if (nums[counter]){
      int i = 2;
      while (counter*i <= limit)
	nums[counter*i++] = false;
    }
  
  primes.clear();
  for (int counter=2; counter <= limit; counter++)
    if (nums[counter])
      primes.insert(counter);
}

