#include <iostream>
using namespace std;

int num(int n = 0) {
	int number = 0;
	if (n == 10){
		cout << "n => " << n << endl;
		return number;
	}
	num(++number);

	cout << "number=> " << number << endl;
	return number;
}
int main () {
	num(0);
	return 0;
}
