#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ImageDithering {
public:
  int count(string dithered, vector <string> screen);
};


int main() {
   
  return 0;
}

int ImageDithering::count(string dithered, vector <string> screen) {
  int counter = 0;
  for(int i = 0; i < dithered.size(); ++i) {
    for(int j = 0; j < screen.size(); ++j) {
      for(int k = 0; k < screen[j].size(); ++k) {
        if(dithered[i] == screen[j][k]) {
          counter++;
        }
      }
    }
  }
  return counter;
}