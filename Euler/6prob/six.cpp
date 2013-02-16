#include <iostream>
using namespace std;

int main () {
	int sumofsquare = 0;
	int squareofsum = 0;

	for (int i =1; i <= 100; ++i) {
		sumofsquare += (i*i);
		squareofsum += i;
	}
	cout << sumofsquare << endl;
	cout << squareofsum << endl;
	squareofsum *= squareofsum;
	cout << squareofsum << endl;
	cout << squareofsum-sumofsquare<< endl;
	return 0;
}
