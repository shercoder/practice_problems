/*
	ID: singh.p2
	PROG: milk2
	LANG: C++
 */

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main () {

	ifstream fin ("milk2.in");
	ofstream fout ("milk2.out");

	int num_farmers = 0;

	int milking_time = 0;
	int idle_time = 0;
	
	int max_milking_time = 0;
	int max_idle_time = 0;

	int first_val = 0;
	int second_val = 0;

	int max_val = 0;
	int min_val = 1000000; 

	fin >> num_farmers;

	bool times[1000000] = {0};

	for (int i = 0; i < num_farmers; ++i) {
		fin >> first_val >> second_val;

		min_val = min(first_val, min_val);
		max_val = max(second_val, max_val);

		for (int range = first_val; range < second_val; ++range) {
			times[range] = 1;
		}
	}

	for (int i = min_val; i < max_val; ++i) {
		if (times[i]) {
			++milking_time;
			idle_time = 0;
			max_milking_time = max(milking_time, max_milking_time);
		}

		else {
			++idle_time;
			milking_time = 0;
			max_idle_time = max(idle_time, max_idle_time);
		}
	}

	fout << max_milking_time << " " << max_idle_time << endl;
	
	return 0;
}
