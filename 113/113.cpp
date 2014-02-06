/**
 * @file   113.cpp
 * @author Behrouz Babaki 
 * @date   Wed Feb  5 23:25:55 2014
 * 
 * @brief   This problem involves the efficient computation of integer roots of numbers. 
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::ostream;
using std::string;
using std::vector;

/*! \class BigInt 113.h "113.h"
 *  \brief a class for stroing big integers
 *
 * This class stores big integers and performs multiplication
 * on them.
 */
class BigInt{

  friend ostream& operator<< (ostream&, const BigInt&);

public:

  /** 
   * \brief default constructor
   */
  BigInt() {}

  /**
   * \brief Constructor for the BigInt class
   * 
   * Gets a string as input and turns it into a BigInt object.
   * Also checks that the string is only composed of digits. If
   * this is not the case, program will terminate.
   * It also stores the string representation of the big integer. 
   *
   * @param str the input string to the problem
   */
  BigInt(string str) : _str(str){

    for (string::const_iterator itr = str.begin(), endItr = str.end();
         itr != endItr; itr++)
      if (static_cast<int> (*itr) < 48 ||
        static_cast<int> (*itr) > 57){
        str.clear();
        cout << "Non-digit character passed to BigInt class. Terminating ..." << endl;
        abort();
      }
    _diglist.reserve(str.length());
    for (string::const_iterator itr = str.begin(), endItr = str.end(); 
         itr != endItr; itr++)
      _diglist.push_back(static_cast<short> (*itr) - 48);
    
  }

  /** 
   * \brief prints the value of the big integer   * 
   */
  void print(void){
    for (vector<unsigned short>::const_iterator itr = _diglist.begin(), endItr = _diglist.end();
         itr != endItr; itr++)
      cout << *itr;
  }

  /** 
   * \brief returns the character representation of the big integer
   * @return a string object representing the big integer
   */
  const string& toString(void) const {
    return _str;
  }

  /** 
   * \brief overloaded operator for multiplication of big integers
   * @param right The right-hand-side operand of multiplication
   * @return The result of multiplication
   */
  BigInt operator* (const BigInt& right) const {
   return this->multiply(right);
  }

  /** 
   * \brief multiplies to big integers
   * @param right The right-hand-side operand of multiplication
   * @return The result of multiplication
   */
  BigInt multiply (const BigInt& right) const {
    BigInt result = right;
    return result;
  }
  
private:
  vector<unsigned short> _diglist; /**< the vector storing digits of long integer */
  string _str;                  /**< the string representation of long integer */
};

/** 
 * \brief overloaded stream output operator
 * 
 * @param out the stream to which this would be concatenated
 * @param Number this big integer object
 * 
 * @return concatenation of character representation of big integer to
 * the given stream
 */
ostream& operator<< (ostream& out, const BigInt& Number){
  out << Number.toString();
  return out;
}

int main(void){
  cout << "Hello World" << endl;
  cout << "113" << endl;

  BigInt first ("1233890");
  first.print();
  cout << endl;
  cout << "now testing the returned string" << endl;
  cout << first.toString() << endl;

  BigInt second("33");
  cout << (first*second).toString() << endl;
  cout << (second*first).toString() << endl;

  cout << "Now testing the stream operator overloading" << endl;
  cout << first * second << endl;
  return 0;
}
