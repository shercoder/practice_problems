#include <iostream>

using namespace std;


int main()
{
	int me = 10;
	const int *p = &me;
	cout << "me= " << me << endl;
	cout << "*p = &me -> " << *p << endl;
	int you = 20;
	p = &you;
	cout << "p=&you -> " << *p << endl;

	//this is wrong because
	//p is a pointer to const int so that means,
	//you cannot change the value at the address
	//that p is holding, which in this case is the
	//address of int me.
	//*p = you;
	

	cout << endl << endl;
	//---------------------------------------------------
	//const pointer to non-const integer
	int us = 30;
	int * const q = &us;
	cout << "us= " << us << endl;
	cout << "*q= " << *q << endl;
	
	//you cannot do this, because q is a constant pointer to int
	//q = &you;
	//cout << "*q you= " << *q << endl;
	
	//but i can do this because q is a constant pointer to non-constant int
	*q = you;
	cout << "*q you= " << *q << endl;
	cout << endl << endl;
	//--------------------------------------------------------------

	//const pointer to const int
	int yours = 100;
	const int * const r = &yours;
	cout << "yours= " << yours << endl;
	cout << "const int* const r= " << *r << endl;
	return 0;
}
