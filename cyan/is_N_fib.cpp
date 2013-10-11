// Check if N is a Fib number

#include <iostream>
#include <cmath>

using namespace std;
//typedef unsigned long long ULL;

// Using Gessel Formula, find if number the resule is a perfect square
bool is_perfect_square(int n) {
  int sqrt_n = sqrt(n);
  return sqrt_n * sqrt_n == n;
}

bool is_fib(int n) {
  int plus  = (5 * n * n)+4; 
  if (is_perfect_square(plus)) return true;

  int minus = (5 * n * n)-4; 
  if (is_perfect_square(minus)) return true;

  return false;
}




int main() {
  int N = 0;
  cin >> N;
  if (is_fib(N))
    cout << N << " is Fib number" << endl;
  else
    cout << N << " is not a Fib number" << endl;
  return 0;
}
