#include <iostream>
#include <string>
using namespace std;

class CCipher {
public:
  string decode(string cipherText, int shift) {
    
    for(int i = 0; i < cipherText.length(); ++i) {
      int index = cipherText[i] - shift;
      if(index >= 65 && index <= 90) {
        cipherText[i] -= shift;
      } else {
        cipherText[i] += (26-shift);
      }
    }
    return cipherText;
  }
};

int main() {
  CCipher cc;
  cout << cc.decode("ABCDEFGHIJKLMNOPQRSTUVWXYZ", 10) << endl;
  return 0;
}