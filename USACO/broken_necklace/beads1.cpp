/*
ID: singh.p2
PROG: beads
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <stdlib.h>
	
using namespace std;
int num_beads = 0;


int main() {
	ofstream fout ("beads.out");
	ifstream fin ("beads.in");
	
	int greatest_beads = 0;

	string necklace;

	fin >> num_beads;
	fin >> necklace;
	
	int left_count = 0;
	int right_count = 0;

	int left_index = 0;
	int right_index = 0; // same as 


	char left_char;
	char right_char;
	int tmp_index; 

	left_index = right_index - 1;
	for(; right_index < num_beads; right_index++, left_index++){   // seperator location
		
		cout << "hello 2"<< endl;
		tmp_index  = right_index;
		right_char = necklace[right_index % num_beads];						 // char right of the seperator	
		if(right_char == 'w'){   // if white then just count as two 
				right_char = necklace[right_index + 1];   //store the char to compare with later
				right_count += 2;	
				tmp_index += 2;
		}
		while((tmp_index != (left_index + num_beads) % num_beads) && (necklace[tmp_index % num_beads] == right_char || necklace[tmp_index % num_beads] == 'w' )){

		// count the number of times that char has been in the string
		cout << "hello 0"<< endl;
				right_count++;														// or if the necklace holds a w at tmp_index
				tmp_index++;
				tmp_index = tmp_index % num_beads;
		}

		// end right count (right of the separator)
		// begin left count  (left of the separator)
		tmp_index = left_index;
		
		left_char = necklace[left_index % num_beads];						 // char right of the seperator	
		if(left_char == 'w'){   // if white then just count as two 
				left_char = necklace[(left_index - 1) % num_beads];   //store the char to compare with later
				left_count += 2;	
				tmp_index = tmp_index - 2;   //initially negative for first iteration
		}
		while((tmp_index != (right_index + num_beads) % num_beads) &&  ( necklace[tmp_index % num_beads] == left_char || necklace[tmp_index % num_beads] == 'w') ){			 // count the number of times that char has been in the string
				left_count++;														// or if the necklace holds a w at tmp_index
		cout << "hello 1"<< endl;
				tmp_index--;
				tmp_index = tmp_index % num_beads;
		}

	if((left_count + right_count) >=  num_beads){    /// should never total greater than the num_beads
		greatest_beads = num_beads;
		break;   // if it was greater than it was num_beads
	}
	else if(greatest_beads < (left_count + right_count)){   // new total found
		//cout << num_beads << endl;
		greatest_beads = left_count + right_count ;
		//cout << greatest_beads << endl;
	}
	left_count = 0;
	right_count = 0 ;

	} // end for all letters in the string (iter by the length of the string)
	
	fout << greatest_beads << endl;
	return 0;
}


