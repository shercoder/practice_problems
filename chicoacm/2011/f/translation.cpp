#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <stack>
using namespace std;

int main(int argc, char const *argv[])
{
  char *line = new char[1000];
  char *token;
  int n = 0;
  cin >> n;
  cin.get();
  stack<string> s;

  while(cin.getline(line, 1000)) {
    token = strtok(line, " ");
    while(token) {
      s.push(token);
      token = strtok(NULL, " ");
    }
    
    while(!s.empty()) {
      cout << s.top() << " ";
      s.pop();
    }
    cout << endl;
    token = NULL;
    delete [] line;
    line = new char[1000];
  }
  return 0;
}