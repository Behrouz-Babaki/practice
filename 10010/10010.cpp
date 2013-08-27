#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using std::cin;
using std::string;
using std::cout;
using std::endl;
using std::getline;
using std::vector;

void checkGrid(const char* const * const , int, int, const char* const * const, const vector<int>&);
bool checkForWord (const char * const * const, int, int, const char* const, int, int, int, int, int);
bool equivLetter (char, char);

int main(void){

  int number_of_cases;
  cin >> number_of_cases;
  cin.get();  // Throw out the newline character
  
  string line;

  for (int counter = 0; counter < number_of_cases; counter++)
    {
      getline (cin, line, '\n');  // Throw out the blank line

      int rows, columns;
      cin >> rows >> columns;
      cin.get(); // Throw out the end of line character

      char ** grid = new char *[rows];
      for (int rowCounter = 0; rowCounter < rows; rowCounter++)
	{
	  char * row = new char [columns];
	  grid[rowCounter] = row;

	  for (int columnCounter = 0; columnCounter < columns; columnCounter ++)
	    cin.get(row[columnCounter]);

	  cin.get(); // Throw out the end of line character
	}

      int number_of_words;
      cin >> number_of_words;
      cin.get();

      char ** words = new char *[number_of_words];
      vector <int> lengths;
      for (int wordCounter = 0; wordCounter < number_of_words; wordCounter++)
	{
	  getline(cin,line);
	  int wordLength = line.length();
	  char *word = new char [wordLength];
	  strncpy(word, line.c_str(), wordLength);
	  words[wordCounter] = word;
	  lengths.push_back(wordLength);
	}
      
      checkGrid (grid, rows, columns, words, lengths);
      
      for (int rowCounter = 0; rowCounter < rows; rowCounter++)
	delete grid[rowCounter];
      delete grid;

      for (int wordCounter = 0; wordCounter < number_of_words; wordCounter ++)
	delete words[wordCounter];
      delete words;
      
    }

  return 0;
}

void checkGrid (const char* const * const grid, int rows, int cols, const char* const * const words , const vector<int>& lengths){
  int number_of_words = lengths.size();
  bool found;
  
  for (int wordCounter = 0; wordCounter < number_of_words; wordCounter++)
    {
      found = false;

      int vLoc, hLoc;
      for (vLoc = 0; vLoc < rows && !found; vLoc ++)
	{
	  for (hLoc = 0; hLoc < cols && !found; hLoc ++)
	    {
	      found = checkForWord (grid, rows, cols, words[wordCounter], lengths[wordCounter], hLoc, vLoc, 1, 0);
	      if (!found)
		found = checkForWord (grid, rows, cols, words[wordCounter], lengths[wordCounter], hLoc, vLoc, -1, 0);
	      if (!found)
		found = checkForWord (grid, rows, cols, words[wordCounter], lengths[wordCounter], hLoc, vLoc, 0, 1);
	      if (!found)
		found = checkForWord (grid, rows, cols, words[wordCounter], lengths[wordCounter], hLoc, vLoc, 0, -1);
	      if (!found)
		found = checkForWord (grid, rows, cols, words[wordCounter], lengths[wordCounter], hLoc, vLoc, 1, 1);
	      if (!found)
		found = checkForWord (grid, rows, cols, words[wordCounter], lengths[wordCounter], hLoc, vLoc, -1, -1);
	      if (!found)
		found = checkForWord (grid, rows, cols, words[wordCounter], lengths[wordCounter], hLoc, vLoc, -1, 1);
	      if (!found)
		found = checkForWord (grid, rows, cols, words[wordCounter], lengths[wordCounter], hLoc, vLoc, 1, -1);
	  }

	  if (found)
	    cout << vLoc + 1 << " " << hLoc  << endl; // hLoc is incremented by for loop
	}
    }
  
  if (found)
    cout << endl;

  return;
}



bool checkForWord (const char * const * const grid, int rows, int cols, const char* const word, int wordLength, int hStrt, int vStrt, int hInc, int vInc)
{
  int counter, hLoc, vLoc;
  
  for (hLoc = hStrt, vLoc = vStrt, counter = 0; counter < wordLength && vLoc >= 0 && vLoc < rows && hLoc >= 0 && hLoc < cols; hLoc += hInc, vLoc += vInc, counter++)
  	 if (!equivLetter(word[counter],grid[vLoc][hLoc]))
  	   return false;

       return  (counter == wordLength);
}
  

bool equivLetter (char first, char second){

  int f = first , s = second;

  if (f >= 97)
    f -= 32;
  if (s >= 97)
    s -= 32;

  return (f == s);
}
