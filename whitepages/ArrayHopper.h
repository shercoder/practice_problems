#ifndef ARRAY_HOPPER_H
#define ARRAY_HOPPER_H

#include <vector>
#include <string>

using namespace std;

typedef unsigned long long LL;

class ArrayHopper {
public:
    ArrayHopper(const string& filename);
    ~ArrayHopper();

    bool load_data();
    vector<LL> find_min_len_hops();

private:
    string filename;
    vector<LL> array;

    LL find_max(int cur, int limit);
    LL convert(const string& str);
};
#endif