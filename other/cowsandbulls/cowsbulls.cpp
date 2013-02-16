#include <iostream>
#include <algorithm>
using namespace std;

int main () {
	string num1 = "19385";
	string num2 = "39786";
	int bull = 0, cow = 0;
	for(int i = 0; i< 5; ++i) {
		for (int j = 0; j < 5; ++j){
			if(num1[i] == num2[j] && i == j)
				++bull;
			else if(num1[i] == num2[j] && i != j)
				++cow;
		}
	}

	cout << "bulls => " << bull << endl;
	cout << "cows => " << cow << endl;
	cout << max(1,1) << endl;
	return 0;
}
