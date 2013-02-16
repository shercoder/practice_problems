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

	//int prev_second_val = 0;

	//bool isEven = true;

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
			//max_milking_time = max(milking_time, max_milking_time);
		}

		else {
			++idle_time;
			milking_time = 0;
			//max_idle_time = max(idle_time, max_idle_time);
		}
	}


	//int* times = new int[num_farmers];
	//int val = 0;

	// for (int i = 0; i < num_farmers*2; ++i) {
	// 	fin >> val;
	// 	times[i] = val;
	// }

	// for (int i = 0; i < num_farmers*2; ++i) {
	// 	if (isEven) {
	// 		if (milking_time < (times[i+1]-times[i])) {
	// 			milking_time += (times[i+1]-times[i]);
	// 		}

	// 		if (times[i] <= times[i-1] && i > 0) {
	// 			milking_time += (times[i+1] - times[i-1]);
	// 			//prev_second_val = times[i+1];				
	// 		}
	// 		//prev_second_val = times[i+1];
	// 		isEven = false;
	// 	}
	// 	else {
			
	// 		//else {
	// 			if (idle_time < (times[i+1]-times[i])) {
	// 				idle_time = (times[i+1]-times[i]);
	// 			}
	// 			isEven = true;
	// 			//prev_second_val = times[i+1];
				
	// 			//cout << "Idle time => " << idle_time << endl;
	// 		//}
	// 	}
	// }

	//while (fin >> first_val >> second_val) {
		//cout << first_val << " " << second_val << " " << prev_second_val << endl;


		// if (isEven) {
		// 	if (milking_time < (second_val-first_val)) {
		// 		milking_time += (second_val-first_val);
		// 		prev_second_val = second_val;
		// 	}
		// 	isEven = false;
		// }
		// else {
		// 	if (first_val <= prev_second_val) {
		// 		milking_time += (second_val - prev_second_val);
		// 		prev_second_val = second_val;				
		// 	}
		// 	else {
		// 		if (idle_time < (first_val-prev_second_val)) {
		// 			idle_time = (first_val-prev_second_val);
		// 			isEven = true;
		// 		}
		// 		prev_second_val = second_val;
				
		// 		cout << "Idle time => " << idle_time << endl;
		// 	}
			
		// }
	//}

	 fout << milking_time << " " << idle_time << endl;
	//fout << max_milking_time << " " << max_idle_time << endl;
	
	return 0;
}