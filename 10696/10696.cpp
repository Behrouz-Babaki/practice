#include <iostream>

using std::cout;
using std::endl;
using std::cin;

size_t f_91(size_t);
size_t vals[112];
bool exists[112];

int main(void) {
  for (size_t counter = 0; counter <= 111; counter++)
    exists[counter] = false;
  for (size_t counter = 101; counter <= 111; counter++)
    vals[counter] = counter - 10;
  for (size_t counter = 100; counter > 0; counter--)
    f_91(counter);

  size_t num;
  cin >> num;
  while (num) {
    cout << "f91(" << num << ") = " << f_91(num) << endl;
    cin >> num;
  }
    
  return 0;
}

size_t f_91(size_t index) {
  if (index >= 101)
    return index - 10;
  if (exists[index])
    return vals[index];
  size_t value = f_91(f_91(index+11));
  vals[index] = value;
  exists[index] = true;
  return value;
}
