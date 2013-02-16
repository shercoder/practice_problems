#include <iostream>
#include <cmath>
using namespace std;

int main () {
	int n = 100;
	long squareofsum = pow(((double)(n*(n+1))/2), 2); //n(n+1)/2 ** 2
	long sumofsquare = (n*(n+1)*(2*n+1))/6;		  //n(n+1)(2n+1)/6
	cout << squareofsum-sumofsquare << endl;
	return 0;
}
