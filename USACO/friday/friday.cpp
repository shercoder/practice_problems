/*
	ID: singh.p2
	PROG: friday
	LANG: C++
 */

#include <iostream>
#include <fstream>

using namespace std;

int main () {

	ifstream infile("friday.in");
	if (!infile.is_open())
	{
		cerr << "Could not open the file" << endl;
		return 1;
	}

	ofstream outfile("friday.out")
;	if (!outfile.is_open())
	{
		cerr << "Could not open friday.out" << endl;
		return 1;
	}

	int N(0);
	infile >> N;
	int timePeriod(1900+N-1);

	int numDays [7] = {0};
	int thirteenth(13);
	int weekDay(0);

	int monthlyDays[] = {31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	for (int i = 1900; i <= timePeriod; ++i) {
		if ((i%4 == 0 && i%100 != 0) || i%400 == 0) {
			monthlyDays[1] = 29;
		}
		else {
			monthlyDays[1] = 28;
		}
		for (int j = 0; j < 12; ++j) {
			thirteenth = thirteenth%7;
			numDays[thirteenth] += 1;
			thirteenth += monthlyDays[j];
		}
	}
	//cout << numDays[i%7] << " ";
	for (int i = 6; i < 13; ++i) 
		outfile << numDays[i%7] << (i==12?'\n':' ');

	return 0;
}