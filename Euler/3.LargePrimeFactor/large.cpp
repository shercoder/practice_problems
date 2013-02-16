#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


/*vector<bool> *p;
int primes(int n )
{
	(*p)[0] = 0;
	(*p)[1] = 0;
	
	int largest = 0;	
	for (int i = 2; i <= n; ++i)
	{
		if((*p)[i])
		{
			for(int j = i*i; j <= n; j+=i)
			{
				(*p)[j] = 0;
			}
			largest = i;
		}
	}	
	return largest;

}

int largestPrime(long int n)
{
	int s = (int)sqrt(n);
	int largest = -1;
	

}*/

long int FermatFactor(long int N) {
	long int a = ceil(sqrt(N));
	long int b2 = a*a-N;
	long int sqrb2 = sqrt(b2);

	while(sqrb2*sqrb2 != b2) {
		a += 1;
		b2 = a*a-N;
		sqrb2 = sqrt(b2);
	}
	return a+sqrt(b2);
}

int main()
{
	const long int num = 600851475143;
	
	cout << FermatFactor(13195) << endl;
	
	return 0;
}
