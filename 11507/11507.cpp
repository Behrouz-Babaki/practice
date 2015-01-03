//============================================================================
// Name        : 11507.cpp
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::endl;
using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::sort;
using std::getline;
using std::ws;

void current_direction(string&, const string&);
char not_direction(char);

int main(void) {
	size_t length;
	cin >> length;
	string bend;
	string current;
	while (length > 0) {
		cin >> bend;
		if (!bend.compare("No"))
			current = "+x";
		else
			current = bend;
		for (int point_counter = length - 2; point_counter > 0;
				point_counter--) {
			cin >> bend;
			current_direction(current, bend);
		}
		cout << current << endl;
		cin >> length;
	}
	return 0;
}

void current_direction(string& current, const string& bend) {
	string next(2, ' ');
	if (!bend.compare("No"))
		return;

	if (!current.compare("+x")){
		current = bend;
		return;
	}

	if (!current.compare("-x")) {
		next[1] = bend[1];
		next[0] = not_direction(bend[0]);
		current = next;
		return;
	}

	if ((current[1] == 'y' || current[1] == 'z') && bend[1] == current[1]) {
		next[1] = 'x';
		if (current[0] == '+')
			next[0] = not_direction(bend[0]);
		else
			next[0] = bend[0];
		current = next;
		return;
	}

}

char not_direction(char direction) {
	if (direction == '-')
		return '+';
	return '-';
}
