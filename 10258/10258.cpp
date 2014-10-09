#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <utility>

using std::cin;
using std::cout;
using std::endl;
using std::istringstream;
using std::string;
using std::ws;
using std::isspace;
using std::priority_queue;
using std::vector;
using std::map;
using std::set;
using std::pair;
using std::make_pair;

struct _team_ {
  size_t team_number;
  size_t num_solved;
  vector<size_t> times;
  size_t time;
};
typedef struct _team_ team;

class comparison {
public:
  bool operator() (const team& left, const team& right) const {
    if (left.num_solved < right.num_solved)
      return true;
    if (left.num_solved == right.num_solved) {
      if (left.time > right.time)
	return true;
      if (left.time == right.time && 
	  left.team_number > right.team_number)
	return true;
    }
    return false;
  }
};

bool is_blank(string&);

int main (void) {
  int number_of_cases;
  string line;
  cin >> number_of_cases >> ws;
  for (int case_cnt = 0; case_cnt < number_of_cases; case_cnt++) {
    set<pair<size_t, size_t> > has_solved;
    map<size_t, team> team_map;
    priority_queue <team, vector<team>, comparison> team_queue;
    getline(cin, line);
    while (!is_blank(line)){
      size_t contestant, problem, time;
      char L;
      istringstream ss(line);
      ss >> contestant >> problem >> time >> L;
      bool has_effect, correct;
      has_effect = false;
      correct = false;

      if (L == 'C' || L == 'I') {
	has_effect = true;
	correct = (L == 'C');
      }

      if (team_map.find(contestant)== team_map.end()) {
	team current_team;
	current_team.team_number = contestant;
	current_team.num_solved = 0;
	current_team.time = 0;
	vector<size_t> current_team_times (9, 0);
	current_team.times = current_team_times;
	team_map[contestant] = current_team;
      }

      if (has_effect && has_solved.find(make_pair(contestant, problem)) == has_solved.end()) {
	if (correct) {
	  has_solved.insert(make_pair(contestant, problem));
	  team_map[contestant].num_solved ++;
	  team_map[contestant].times [problem-1] += time;
	}
	else
	  team_map[contestant].times [problem-1] += 20;
      }
      getline(cin, line);
    }
    
    for (auto current_team_pair : team_map) {
      team current_team = current_team_pair.second;
      size_t total_time = 0;
      for (size_t counter = 0; counter < 9; counter++)
	if (has_solved.find(make_pair(current_team.team_number, counter+1)) != has_solved.end())
	  total_time += current_team.times [counter];
      current_team.time = total_time;
      team_queue.push(current_team);
    }
    
    while (!team_queue.empty()) {
      team current_team = team_queue.top();
      team_queue.pop();
      cout << current_team.team_number << " " 
	   << current_team.num_solved << " " 
	   << current_team.time << endl;
    }

    if(case_cnt < number_of_cases - 1)
      cout << endl;
  }
  return 0;
}

bool is_blank (string& str) {
  string::iterator itr  =  str.begin();
  while (itr != str.end())
    if (!isspace(*itr++))
      return false;
  return true;
}
