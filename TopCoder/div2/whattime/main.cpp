#include "whattime.cpp"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	Time t;
	cout << t.whatTime(0) << endl;
	cout << t.whatTime(86399) << endl;
	return 0;
}