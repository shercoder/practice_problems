#include <iostream>
#include <map>

using namespace std;

int main()
{
	char l[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
			'J', 'K', 'L', 'M', 'N', 'O', 'P', 'R',
			'S', 'T', 'U', 'V', 'W', 'X', 'Y'};
	
	map<char, int> keypad;
	int counter = 0;
	int num = 2;
	for (int i = 0; i < 24; ++i)
	{
		keypad[l[i]] = num;
	        counter++;
		if (counter == 3)
		{
			counter = 0;
			num++;
		}

	}

/*	map<char, int>::iterator it = keypad.begin();
	for (; it != keypad.end(); ++it)
	{
		cout << (*it).first << "= " << (*it).second << endl;
	}*/


	string input("");
	int n = 0;
	cin >> n;
	int i = 0;
	string arr[n];
	while (n)
	{
		cin >> input;
		arr[i] = input;
		i++;
		n--;
	}
	


	return 0;
}
