#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
  int n = 0;
  cin >> n;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < i+1; j++) {
      for(int k = 1; k <= i+1; k++) {
        cout << "*";
      }
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}