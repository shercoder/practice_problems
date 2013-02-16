#include <iostream>
#include "Thing.h"

using namespace std;

int main()
{
    Thing t;
    cout << t.getsize() << endl;
    Thing t2(2);
    Thing t4(7);
    t.somefunction(t2);
    Thing t3(t2);
    t = t2.anotherfunction();
    t2 = t4;

    if( t != t2 )
        cout << "t != t2" << endl;

    cout << t.getsize() << endl;
    cout << t2.getsize() << endl;
    cout << t3.getsize() << endl;
    return 0;
}
