/*
	ID: singh.p2
	PROG: ride
	LANG: C++
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream infile("ride.in", ifstream::in);
	if (!infile.is_open())
	{
		cerr << "Could not open the file" << endl;
		return 1;
	}

	ofstream outfile("ride.out", ofstream::out);
	if (!outfile.is_open())
	{
		cerr << "Could not open ride.out" << endl;
		return 1;
	}

	string cometName("");
	string groupName("");
	
	while (!getline(infile, cometName).eof())
	{
		getline(infile, groupName);	
		
		int cProduct = 1;
		int gProduct = 1;
		for (int i = 0; i < cometName.length(); ++i)
				cProduct *= cometName[i]-64;
		for (int i = 0; i < groupName.length(); ++i)
				gProduct *= groupName[i]-64;
		
		if ((cProduct%47) == (gProduct%47))
			outfile << "GO" << endl;
		else 
			outfile << "STAY" << endl;
	}

	infile.close();
	outfile.close();
	return 0;
};
