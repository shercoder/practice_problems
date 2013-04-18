#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
  int t = 0;
  cin >> t;
  int n = 0;
  int tmp = 0;
  while(t) {
    cin >> n;
    // tmp = n;
    for(int i = 1; i <= (n/2); ++i) {
      if(n%i == 0) cout << i << " ";
    }
    cout << n << endl;
    --t;
  }
  return 0;
}