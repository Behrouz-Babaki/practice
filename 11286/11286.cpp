#include <iostream>
#include <string>
#include <map>
#include <set>
#include <utility>

using std::cin;
using std::endl;
using std::cout;
using std::ws;
using std::getline;
using std::string;
using std::pair;
using std::make_pair;
using std::map;
using std::set;

int main(void) {
  size_t num_students;
  cin >> num_students >> ws;
  while (num_students) {
    size_t max_cnt = 1;
    map<set<size_t>, size_t> course_map;
    map<set<size_t>, size_t>::iterator itr;
    for (size_t student_cnt = 0; student_cnt < num_students; student_cnt++) {
      set<size_t> courses;
      for (size_t course_cnt = 0; course_cnt < 5; course_cnt++) {
	size_t current_course;
	cin >> current_course;
	courses.insert(current_course);
      }
	
      itr  = course_map.find(courses);
      if (itr == course_map.end())
	course_map.insert(make_pair(courses, 1));
      else {
	itr->second++;
	if (itr->second > max_cnt)
	  max_cnt = itr->second;
      }
    }
    size_t pop = 0;
    for (itr = course_map.begin(); itr != course_map.end(); itr++)
      if (itr->second == max_cnt)
	pop += max_cnt;
    cout << pop << endl;
    cin >> num_students >> ws;
  }
  return 0;
}

