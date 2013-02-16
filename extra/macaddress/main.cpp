#include <iostream>
#include <stdint.h>
#include <algorithm>
#include <vector>

using namespace std;

struct mystruct{
	uint8_t macAddr[2];
};
bool myfunction (int i,int j) { return (i<j); }
int main()
{
	mystruct newstruct[3];
	newstruct[0].macAddr[0] = '6';
	newstruct[0].macAddr[1] = 'a';

	newstruct[1].macAddr[0] = '7';
	newstruct[1].macAddr[1] = '2';

	newstruct[2].macAddr[0] = '1';
	newstruct[2].macAddr[1] = '3';

	for (int i = 0; i < 3; ++i)
	{
		for (int j=0; j<2; ++j)
			cout << newstruct[i].macAddr[j];
		cout << endl;
	}

	vector<mystruct> myvector (newstruct, newstruct+3);
	cout << myvector << endl;
	//sort(myvector.begin(), myvector.end());


	return 0;
}
