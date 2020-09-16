#ifndef __BASE_H__
#define __BASE_H__
/*
* This is the parent class of all the opperations
*/
#include <string>
#include <math.h>
class Base {
public:
    /* Constructors */
    Base() { };

    /* Pure Virtual Functions */
    //This one will return the value of the result of the operation
    virtual double evaluate() = 0;
    //This one will return a string of the whole problem
    virtual std::string stringify() = 0;
};

#endif //__BASE_H__