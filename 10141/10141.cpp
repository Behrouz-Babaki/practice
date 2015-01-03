//============================================================================
// Name        : 10141.cpp
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

struct proposal {
	string name;
	size_t num_r_met;
	double price;
};

int main(void) {
	size_t rfp_counter = 0;
	size_t num_requirements, num_proposals;
	cin >> num_requirements >> num_proposals >> ws;
	bool first = true;
	while (num_requirements > 0 && num_proposals > 0) {
		string requirement_name;
		for (int req_counter = 0; req_counter < num_requirements; req_counter++)
			/* throwing out the requirement name*/
			getline (cin,requirement_name);
		vector<struct proposal> proposals;
		for (int prop_counter = 0; prop_counter < num_proposals;
				prop_counter++) {
			struct proposal current_proposal;
			getline(cin, current_proposal.name);
			cin >> current_proposal.price >> current_proposal.num_r_met >> ws;
			proposals.push_back(current_proposal);

			string req_name;
			for (int req_counter = 0; req_counter < current_proposal.num_r_met;
					req_counter++)
				/* throwing out requirement names */{
				getline(cin, req_name);
			}
	}
		sort(proposals.begin(), proposals.end(),
				[](const struct proposal& left, const struct proposal& right) -> bool
				{if (left.num_r_met ==right.num_r_met)
					return left.price < right.price;
				return left.num_r_met > right.num_r_met;});
		if (!first)
			cout << endl;
		else
			first = false;
		cout << "RFP #" << rfp_counter+1 << endl;
		cout << proposals.front().name << endl;


	cin >> num_requirements >> num_proposals >> ws;
	rfp_counter++;
}
return 0;
}
