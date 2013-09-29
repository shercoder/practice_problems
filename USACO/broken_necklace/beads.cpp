/*
ID: singh.p2
LANG: C++
TASK: beads
*/
#include <fstream>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int max_beads(char *necklace);

int n = 0;

int main() {
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");

    string necklace;

    fin >> n;
    fin >> necklace;

    char broken_necklace[n];
    int max = -1;

    for (int i = 0; i <= n-1; ++i) {
        int j_max = 0;
        for (int j = i+1; j <= n-1; ++j, j_max = j-i-1) {
            broken_necklace[j-i-1] = necklace[j]; // j-i-1 to start at index 0
        }

        for (int j = 0; j <= i; ++j, ++j_max) {
            broken_necklace[j_max] = necklace[j];
        }

        int total = max_beads(broken_necklace);
        if (total > max) max = total;
    }

    if(max == 2*n) max /= 2;
    fout << max << endl;
    return 0;
}

int max_beads(char *necklace) {

    // count the left side
    char flag = necklace[0];
    int i = 0;
    if(necklace[0] == 'w') {
        while(necklace[i] == 'w') ++i;

        // if we went through entire string and still seeing 'w'
        if (i == n) flag = 'w';
        else flag = necklace[i];
    }

    int counter = 0;
    i = 0;
    while(flag == necklace[i] || necklace[i] == 'w') {
        ++counter;
        necklace[i] = flag;
        ++i;
    }

    // count the right side
    i = n-1;
    flag = necklace[n-1];
    if (necklace[n-1] == 'w') {
        while(necklace[i] == 'w') --i;
        if (i < 0) flag = 'w';
        else flag = necklace[i];
    }

    i = n-1;
    while(flag == necklace[i] || necklace[i] == 'w') {
        ++counter;
        --i;
    }
    return counter;
}
