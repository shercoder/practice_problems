#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

typedef long long LL;
vector<bool> primes;

void sieve(int n) {
  primes[0] = 0;
  primes[1] = 0;
  int m = (int)sqrt(n);
  for (int i = 2; i <= m; i++) {
  	if (primes[i]) {
  	  for (int k = i*i; k <= n; k+=i) {
  	    primes[k] = 0;
  	  }
  	}
  }
    
}

int main()
{
	LL num = 600851475143;
	primes = vector<bool>(1000000,1);

  sieve(1000000);
  int largest = 0;

	for(int i = 1; i < primes.size(); i++) {
		if(!(num%i) && primes[i]) {
			num /= i;
			largest = i;
		}
	}
	cout << largest << endl;
	return 0;
}
