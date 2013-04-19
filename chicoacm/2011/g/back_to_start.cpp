#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
  int T = 0, D = 0, x = 0, y = 0;
  char* dd = new char[5]; // direction distance
  int total = 0;
  int holder = 0;

  cin >> T;
  cin.get();
  int c = 1;

  while(T) {
    cin >> D;
    cin.get();
    while(D) {
      cin.getline(dd, 5);
      // printf("%s\n", dd);
      if(dd[0] == 'N') {
        holder = atoi(dd+1);
        y += holder;
      } else if(dd[0] == 'S') {
        holder = atoi(dd+1);
        y -= holder;
      } else if(dd[0] == 'E') {
        holder = atoi(dd+1);
        x += holder;
      } else if(dd[0] == 'W') {
        holder = atoi(dd+1);
        x -= holder;
      }
      total += holder;

      delete [] dd;
      dd = new char[5];
      D--;
    }
    cout << "Case " << c << endl
        << "Distance Walked: " << total << endl
        << "Distance to Start: " << (int)sqrt((x*x + y*y)) << endl << endl;
    total = 0, x = 0, y = 0, c++;
    T--;
  }
  return 0;
}