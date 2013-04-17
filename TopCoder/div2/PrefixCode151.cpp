/*Problem Statement
    
A prefix code is a set of words in which no word is a prefix of another word 
in the set. A word v is said to be a prefix of a word w if w starts with v.  
An important property of prefix codes is that they are uniquely decodable. 
Prefix codes are commonly used - telephone numbers are an everyday example 
(as you probably don't want a stranger to pick up the phone call you make just 
 because his number is a prefix of the number you intend to dial). Prefix codes 
are also very popular in computer science, the Huffman code used for data 
compression being a famous example.  Given a vector <string> words, return 
the string "Yes" if that set of words is a prefix code or return the string 
"No, i" if it is not, where i is replaced by the lowest 0-based index of a 
string in words that is a prefix of another string in words. (That index should 
have no extra leading zeros.)

Definition
    
Class:
PrefixCode
Method:
isOne
Parameters:
vector <string>
Returns:
string
Method signature:
string isOne(vector <string> words)
(be sure your method is public)
    

Notes
-
Letters are case sensitive (e.g. "No" is not a prefix of "not").
-
Do not forget the single space between the comma and i in "No, i"
Constraints
-
words contains between 1 and 50 elements, inclusive.
-
Each element of words contains between 1 and 50 characters, inclusive.
-
Each element of words consists only of characters '0'-'9', 'A'-'Z' and 'a'-'z', inclusive.
-
No two elements of words are equal (as the input represents a set).
Examples
0)

    
{"trivial"}
Returns: "Yes"
As there is only one word, no word can be the prefix of another, so this is a 
trivial example of a prefix code.
1)

    
{"10001", "011", "100", "001", "10"}
Returns: "No, 2"
"100" (at index 2) and "10" (at index 4) are both a prefix of "10001" and "10" 
is also a prefix of "100", therefore it is no prefix code. "100" is the prefix 
with the lowest index.
2)

    
{"no", "nosy", "neighbors", "needed"}
Returns: "No, 0"

3)

    
{"1010", "11", "100", "0", "1011"}
Returns: "Yes"

4)

    
{"No", "not"}
Returns: "Yes"

This problem statement is the exclusive and proprietary property of TopCoder, Inc. 
Any unauthorized use or reproduction of this information without the prior 
written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. 
All rights reserved.*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class PrefixCode {
public:
  string isOne(vector <string> words) {
    if(words.size() == 1) return "Yes";
    for(int i = 0; i < words.size(); ++i) {
      for(int j = 0; j < words.size(); ++j) {
        if(words[i] == words[j]) continue;
        if(words[i].length() > words[j].length()) continue;
        if(words[j].find(words[i]) == 0) {
          stringstream ss;
          ss << i;
          return "No, " + ss.str();
        }
      }
    }
    return "Yes";
  }
};

int main() {
  // {"10001", "011", "100", "001", "10"}
  // {"1010", "11", "100", "0", "1011"}
  std::vector<string> v;
  v.push_back("1010");
  v.push_back("11");
  v.push_back("100");
  v.push_back("0");
  v.push_back("1011");
  PrefixCode pc;
  cout << pc.isOne(v) << endl;
  return 0;
}