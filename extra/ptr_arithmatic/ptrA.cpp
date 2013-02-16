#include <iostream>

using namespace std;

int main()
{
	int a[5] = {1, 5, 20, 15, 24};

	int* p = new int;

	p = a;

	cout << *p << endl;
	cout << *(p+1) << endl;
	p++;
	cout << *p << endl;
	p--;
	cout << *p << endl;
	cout << *(p+19) << endl; //this is different than *p+19
	//*p+19 will add 19 to the value at *p
	//whereas *(p+19) will get the value at index 19

	return 0;
}
