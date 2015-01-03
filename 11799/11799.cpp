//============================================================================
// Name        : 11799.cpp
//============================================================================

#include <iostream>
using std::endl;
using std::cout;
using std::cin;

int main(void) {
	size_t num_cases;
	cin >> num_cases;
	for (size_t case_counter = 0; case_counter < num_cases; case_counter++) {
		int num_scaries;
		cin >> num_scaries;
		size_t min_speed = 0;
		size_t scary_speed;
		for (size_t scary_counter = 0; scary_counter < num_scaries;
				scary_counter++){
			cin >> scary_speed;
			if (scary_speed > min_speed)
				min_speed = scary_speed;
		}
		cout << "Case " << case_counter + 1 << ": " << min_speed << endl;
	}
	return 0;
}
