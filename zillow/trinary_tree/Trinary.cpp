#include <iostream>
#include <fstream>
using namespace std;

#include "NodeTree.h"

int main(int argc, const char* argv[]) {
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <input_file>" << endl;
        return 1;
    }

    ifstream ifs(argv[1]);
    if (!ifs.is_open()) {
        cout << "Could not open " << argv[1] << " successfully." << endl;
        return 1;
    }


    NodeTree *tree = new NodeTree();
    int next = 0;
    char mode;
    string buffer;
    while(!ifs.eof()) {
        getline(ifs, buffer);
        sscanf(buffer.c_str(), "%c %d", &mode, &next);
        switch(mode) {
            case 'A':
                tree->insert(next);
                break;
            case 'R':
                if (tree->remove(next)) {
                    cout << "Successfully deleted " << next << endl;
                } else {
                    cout << "Did not find " << next << endl;
                }
                break;
            case 'P':
                tree->print(); cout << endl;
                break;
            default:
                break;
        }
    }

    delete tree;
    ifs.close();
    return 0;
}