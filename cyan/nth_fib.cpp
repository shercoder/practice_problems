#include <iostream>
#include <cmath>
using namespace std;

void first_n_fibnums(int n) {
  if (n == 0 || n == 1) return;
  int a = 0, b = 1;
  while(n > 0) {
    cout << a << " " << b  << endl;
    int t = b;
    b += a;
    a = t;
    --n;
  }
}

int fib_recursive(int n) {
  if (n == 0) return 0;
  if (n == 1) return 1;
  return fib_recursive(n-1) + fib_recursive(n-2);
}

typedef unsigned long long ULL;

// using Binet's formula
ULL nth_fib(int n) {
  double phi = (1 + sqrt(5))/2;
  double phi_neg = 1 - phi;

  return (pow(phi, n) - pow(phi_neg, n))/sqrt(5);
}

int main() {
  first_n_fibnums(5);
  int n = 0;
  cin >> n;
  cout << n << "th term ==> " << nth_fib(n) << endl;
  return 0;
}
