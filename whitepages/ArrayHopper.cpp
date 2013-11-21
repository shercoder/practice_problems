#include "ArrayHopper.h"

#include <exception>
#include <typeinfo>
#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;

ArrayHopper::ArrayHopper(const string& fname) : filename(fname)
{}

bool ArrayHopper::load_data() {
    ifstream in_file(filename.c_str());
    if (!in_file.is_open()) {
        cout << "ERROR: Could not open file." << endl;
        return false;
    }

    string next_num;

    // Read input from the file
    while (getline(in_file, next_num)) {
        LL num;
        try {
             num = convert(next_num);
        } catch (...) {
            cout << "ERROR: File must contain only numbers." << endl;
            return 1;
        }

        array.push_back(num);
    }
}

// Find minimum length hops
vector<LL> ArrayHopper::find_min_len_hops() {
    LL n = array.size();
    vector<LL> hops;
    hops.push_back(0);
    for(int i = 0; i + array[i] <= n - 1;) {
        i = find_max(i, i + array[i]);
        if (i == -1) {
            vector<LL> empty;
            return empty;
        }
        hops.push_back(i);
    }

    return hops;
}

// find max index that we can hop
LL ArrayHopper::find_max(int cur, int limit) {
    LL max_pos = cur, max_val = 0;
    for (LL i = cur; i <= limit; ++i) {
        if (array[i] > max_val) {
            max_pos = i;
            max_val = array[i];
        }
        max_val--;
    }

    // This happens when the values at index are 0. Meaning we can hop
    if (max_pos == cur) return -1;
    return max_pos;
}

/**
 * Check if each input is a valid number
 */
LL ArrayHopper::convert(const string& str)
{
    stringstream ss(str);

    LL i;
    if ((ss >> i).fail() || !(ss >> std::ws).eof())
    {
        throw std::bad_cast();
    }
    return i;
}
