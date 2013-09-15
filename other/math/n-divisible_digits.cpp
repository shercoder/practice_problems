#include <iostream> 
#include <cstdlib>
#include <cmath>

using namespace std;

int main() {
  int n = 0, m = 0;
  cin >> n >> m;

  int i = (int)pow(10.0,(double) n) - 1;
  cout << i - (i%m) << endl;
  return 0;
}
