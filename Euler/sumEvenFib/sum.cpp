#include <iostream>
#include <vector>
using namespace std;

int main ()
{
	int max = 4000000;
//	int max = 50; //ans = 44
	int first = 1;
	int second = 2;
	int result = 0;
	int sum = second;
	//vector<bool> fib(max, 0);
	
	for (int i = 0; i < max; ++i)	
	{
		result = first + second;
		first = second;
		second = result;

		if (result > max)
			break;
		if (result%2 == 0)
			sum += result;
			//	fib[result] = 1;
	}

	cout << sum << endl;

	sum = 2;
	first = 1;
	second = 2;
	result = 0;
	while((first+second)<=max)
	{
		result = first + second;
		first = second;
		second = result;
		if (result%2 == 0)
			sum += result;
	}
	cout << sum << endl;
	return 0;
}
