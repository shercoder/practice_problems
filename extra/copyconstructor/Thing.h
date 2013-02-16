#ifndef THING_H
#define THING_H

#include <iostream>
using std::cerr;
using std::endl;

class Thing
{
    public:

        Thing ()
        {
            size = 3;
            cerr << "default constructor" << endl;
        }

        Thing (int newsize) : size(newsize)
        {
            cerr << " overloaded constructor" << endl;
        }

        //making a copy of the object of this class
        Thing (const Thing& t)
        {
            size = t.size;

            cerr << "copy constructor" << endl;
        }

        const Thing& operator= (const Thing& T)
        {
            size = T.size;
            cerr << "assignment operator" <<endl;

            return *this;
        }

        bool operator== (const Thing& right) const
        {
            cerr << "== called" << endl;
            if ( size != right.size )
                return false;

            return true;
        }

        bool operator!= (const Thing& right) const
        {
            cerr << "!= called" << endl;
            return !(*this == right);
        }



        //copy constructor was called because Thing is being passed by value
        void somefunction ( Thing )
        {
            cerr << "some function was called" << endl;
        }

        //returning Thing by value
        //copy constructor was called
        Thing anotherfunction()
        {
            return *this;
        }

        int getsize() const
        {
            return size;
        }

        private:
            int size;
};

#endif

