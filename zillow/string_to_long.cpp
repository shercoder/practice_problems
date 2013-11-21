#include <iostream>
#include <string>
#include <cassert>
#include <limits>
using namespace std;

/**
 * Limitations: Definition of long can be architecture dependent.
 *              For example, an architecture can define long as 4-byte
 *              or it can be 8-byte.
 *              Another limitation we have is the long string can be
 *              bigger than LONG_MAX limit, and this solution will return
 *              either negated value or some of the upper bits will be 
 *              ignored and the number will be surprisingly different.
 */
long stringToLong(string s) {
  if (s.empty()) return numeric_limits<long>::infinity();
  int len = s.size();
  long val = 0;
  bool isNeg = false;
  int i = 0;

  // Check if it is a negative number
  if (s[0] == '-') {
    isNeg = true;
    i = 1;
  }

  for (; i < len; ++i) { 
    char c = (s[i] - '0');
    
    // Check if char is other than a digit between 0 and 9
    if ((short)c < 0 || (short)c > 9)  return numeric_limits<long>::infinity();
      
    val *= 10;
    val += c;
  }

  if (isNeg) val *= -1;
  return val;
}

void test() {
  assert(stringToLong("123") == 123);
  assert(stringToLong("-123") == -123);
  assert(stringToLong("12e3") == numeric_limits<long>::infinity());
  
  // 9223372036854775807 + 1
  // Result will be -9223372036854775808 
  cout << stringToLong("9223372036854775808") << endl; 

  // Result will be very different
  cout << stringToLong("19223372036854775808") << endl; 
}

int main() {
  cout << "Long MAX on this system = " << numeric_limits<long>::max() << endl;
  test();
  return 0;
}
