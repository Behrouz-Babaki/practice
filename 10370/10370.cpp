#include <iostream>
#include <vector>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::setprecision;
using std::fixed;

int main(void) {
  size_t num_cases;
  cin >> num_cases;
  for (size_t case_counter = 0; case_counter < num_cases; case_counter++) {
    size_t num_students;
    cin >> num_students;
    vector<size_t> grades(num_students);
    size_t sum = 0;
    for (size_t student_counter = 0; student_counter < num_students; student_counter++) {
      cin >> grades[student_counter];
      sum += grades[student_counter];
    }
    double avg = sum /num_students;
    size_t num_above = 0;
    for (size_t student_counter = 0; student_counter < num_students; student_counter++) 
      if (grades[student_counter] > avg)
	num_above++;
    cout << fixed << setprecision(3) << (float)num_above/num_students*100 << "%" << endl;
  }
  return 0;
}
