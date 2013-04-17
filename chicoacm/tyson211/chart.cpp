#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  const int MAX = 100;
  int largest = 0, w = 0;
  int values[MAX] = {0};
  for (int i = 0; i < MAX; ++i) {
    cin >> values[i];
    if(values[i] == 0) break;
    ++w;
    if(values[i] > largest) largest = values[i];
  }

  cout << "------ left to right --------" << endl << endl;
  for (int i = 0; i < w; ++i) {
    cout << setw(values[i]+1) << setfill('*') << '\n';
  }
  cout << "-----------------------------------------------" << endl << endl;

  cout << "------ right to left --------" << endl << endl;
  for (int i = 0; i < w; ++i) {
    for (int k = 0; k < largest-values[i]; ++k) {
      cout << ' ';
    }
    cout << setw(values[i]+1) << setfill('*') << '\n';
  }
  cout << "-----------------------------------------------" << endl << endl;

  cout << "------ bottom up --------" << endl << endl;
  for(int j = 0; j < largest; ++j) {
    for (int i = 0; i < w; ++i) {
      cout << (j + values[i] >= largest ? '*' : ' ');
    }
    cout << endl;
  }
  cout << "-----------------------------------------------" << endl << endl;

  cout << "------ top down --------" << endl << endl;
  for(int j = 0; j < largest; ++j) {
    for (int i = 0; i < w; ++i) {
      cout << (values[i] - j <= 0 ? ' ' : '*');
    }
    cout << endl;
  }

  return 0;
}