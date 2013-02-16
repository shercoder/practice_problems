/*
	ID: singh.p2
	PROG: gift1
	LANG: C++
 */
#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <vector>


using namespace std;


int main () {

	ifstream infile("gift1.in", ifstream::in);
	if (!infile.is_open())
	{
		cerr << "Could not open the file" << endl;
		return 1;
	}

	ofstream outfile("gift1.out", ofstream::out);
	if (!outfile.is_open())
	{
		cerr << "Could not open gift2.out" << endl;
		return 1;
	}

	map<string, int> group;
	vector<string> names;
	int money = 0;
	int numPeople = 0;
	string num("");

	getline(infile, num);
	numPeople = atoi(num.c_str());

	num.empty();

	for (int i = 0; i < numPeople; ++i) {
		getline(infile, num);
		group.insert(pair<string,int>(num, 0));
		names.push_back(num);
		cout << group.find(num)->first << "->" << group[num] << endl;
	}

	string giver("");
	string temp("");


	while(!getline(infile,giver).eof()) {
		getline(infile,temp);
		istringstream iss (temp, istringstream::in);
		iss >> money >> numPeople;

		int moneyToDivide = 0;
		if (numPeople > 0) {
			moneyToDivide = money/numPeople;
			group[giver] -= (moneyToDivide*numPeople);
		}

		
		for (int i = 0; i < numPeople; ++i) {
			string receiver("");
			getline(infile, receiver);
			group[receiver] += moneyToDivide;
		}

	}

	for(int i = 0; i < names.size(); ++i)
		cout << names[i] << endl;

	vector<string>::iterator it = names.begin();
	for (; it != names.end(); ++it) {
		//cout << it->first << "->" << it->second << endl;
		outfile << group.find(*it)->first << " " << group[*it] << endl;
	}



	return 0;
}