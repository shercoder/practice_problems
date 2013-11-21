/**
 * Author: Pardeep Singh
 * Solution for: Whitepages.com
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <exception>
#include <typeinfo>
#include "ArrayHopper.h"

using namespace std;

typedef unsigned long long LL;

int main(const int argc, const char *argv[]) {
    if (argc != 2) {
        cout << "Usage: " << argv[0] <<  " <input_filename>" << endl;
        return 1;
    }

    ArrayHopper *hopper = new ArrayHopper(argv[1]);

    if (!hopper->load_data()) return 1;

    // find hops
    vector<LL> hops = hopper->find_min_len_hops();

    if (hops.empty()) {
        cout << "failure" << endl;
        return 0;
    }

    for (LL i = 0; i < hops.size(); ++i) {
        cout << hops[i] << ", ";
    }
    cout << "out" << endl;

    return 0;
}