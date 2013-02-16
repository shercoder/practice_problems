#include <iostream>
#include <cctype>

using namespace std;

int main()
{
    cout << "Number: " << endl;
    int number;
    cin >> number;
    cout << "Char: " << endl;
    cin.ignore(); 	//this line is important
    char c;
    cin.get(c);

    cout << number << " " << c << endl;

    cout << (int)'a' << endl;
    cout << static_cast<char>(toupper('a')) << endl;
	cout << toupper('a') << endl;
	return 0;
}
