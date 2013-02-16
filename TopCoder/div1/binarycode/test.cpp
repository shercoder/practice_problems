#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	string q("123210122");
	string output[2] = {"NONE", "NONE"};

	
	string p("");

	//assuming p[0] == 0
	if (q[0] == '1') {
		p = "01";
		for(int i = 1; i < q.length(); ++i) {
			(q[i]-(p[i]+p[i-1]));
		}
	}
	cout << p << endl;
	return 0;
}