#include <iostream>

using namespace std;

typedef int* IntPointer;

void sneaky(IntPointer temp)
{
	*temp = 99;
	cout << "Inside function call *temp == " << *temp << endl;
}

int main()
{
	IntPointer p;
	p = new int;
	*p = 77;
	cout << "Before call to function *p == " << *p << endl;

	sneaky(p);

	cout << "After calll to function *p == " << *p << endl;

	delete p;
	p = NULL;

	return 0;
}
