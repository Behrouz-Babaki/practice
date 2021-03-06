#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
using namespace std;

/* Experiences:
   1. How to use (const) multi-dimensional arrays as function argument (using references)
   2. How to set string stream values
   3. How to check exceptions for string streams and cin.
   4. When the input is piped in, you don't have to load all the lines into the memory. 
   The most important lesson learned was that you should use !ss.fail() instead of ss.good(), as
   ss.good() will be false if the whole stream is consumed previously (as ss.eof() will be true even if
   the stream has just reached its end)
   
 */

void find_solution (const int (&nums)[3][3] , char * input , int start , int end);
int compute_val (char* input , const int (&nums)[3][3]);
bool lexComp (char* first , char* second , int);

int best_val;
char best_str[4];

int main (void){
  
  istringstream ss;
  string line;
  int numbers[3][3];
  int bin;
  int color;

do{
  getline(cin,line);
  if (cin.good()){
    ss.str(line);
    ss.clear();
	
    for (bin = 0 ; bin < 3 ; bin++)
	  for (color = 0 ; color < 3 ; color++)
	    ss >> numbers[bin][color];

    if (!ss.fail()){
    best_val = -1;
    strcpy(best_str , "CBG");
  
    char initial_str[4];
    strcpy(initial_str , best_str);
    find_solution (numbers , initial_str , 0 , 2);
    cout << best_str << " " << best_val << endl;
    }

  else{
    cout << "ss not good" << endl;
    cout << ss.eof() << "\t" << ss.fail() << "\t" << ss.bad() << endl;
  }
  }
 }while (cin.good());
 
  
  return 0;
}

void find_solution (const int (&nums)[3][3] , char * input , int start , int end){
  if (start == end){
    int current_val = compute_val(input , nums);
    if (best_val <0 || best_val >  current_val || (best_val == current_val && lexComp(input , best_str , 0))){
      best_val = current_val;
      strcpy(best_str , input);
    }
  }
  
  char t;
  for (int index = start ; index <=  end ; index++){
    t = input[index] , input[index] = input[start] , input[start] = t;
    find_solution(nums , input , start+1 , end);
    t = input[index] , input[index] = input[start] , input[start] = t;
  }
}

int compute_val (char* input , const int (&nums)[3][3])
{
  char codes[4];
  strcpy(codes , "BGC");
  
  int val = 0;

  for (int bin = 0 ; bin < 3 ; bin++)
    for (int color = 0 ; color < 3 ; color++)
      if (input[bin] != codes[color])
	val += nums[bin][color];

  return val;
}

bool lexComp (char* first , char* second , int index){
  if (first[index] < second[index])
    return true;
  
  if (first[index] > second[index])
    return false;
  
  if (index < 2)
    return (lexComp(first , second , index + 1));

	    return false;
}
