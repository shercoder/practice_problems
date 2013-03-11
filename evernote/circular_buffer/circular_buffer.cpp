#include <iostream>
#include <list>
#include <string>

using namespace std;

int main() {
  int N = 0;
  cin >> N;
  cin.get();
  list<string> container;

  string token;
  string line;
  int lines = 0;
  int size = 0;

  while(cin >> token) {
    if(token.compare("A") == 0) {
      cin >> lines;
      for(int i = 0; i < lines; ++i) {
        cin >> line;
        if(size < N) {
          container.push_back(line);
          ++size;
        } else {
          container.pop_front();
          container.push_back(line);
        }
      }
    } else if(token.compare("R") == 0) {
      cin >> lines;
      for(int i = 0; i < lines; ++i) {
        if (container.size() > 0) {
          --size;
          container.pop_front();
        } else {
          break;
        }
      }
    } else if(token.compare("L")) {
      list<string>::iterator it=container.begin();
      if(it != container.end()) {
        for (; it != container.end(); ++it) {
          cout << *it << endl;
        } 
      }
    } else if(token.compare("Q") == 0) {
      break;
    }
  }

  return 0;
}
