#include <iostream>
using namespace std;

#define CHECK_BIT 8

int main () {
	cout << "Calculates the sign of a number: " << endl;
	int v = -2;
	// portable
	int sign = -(int)((unsigned int)((int)v) >> (sizeof(int) * CHECK_BIT -1));
	cout <<  "sign of " << v << " => " << sign << endl; 
	
	// this is not portable
	// meaning on different architecture, this wouldn't work	
	int g = 22;
        cout << "sign of " << g << " => " << (g >> ((sizeof(int) * CHECK_BIT - 1))) << endl;
	
	cout << "------------------------------------------"<< endl;

	cout << "Find if x and y has opposite signs: " << endl;
	int x = 2;
	int y = -2;
	cout << "x => " << x << endl << "y => " << y << endl;
	cout << "Sign is opposite => " << boolalpha << ((x^y)<0) << endl << endl;
	return 0;
}
