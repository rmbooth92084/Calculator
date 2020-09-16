#ifndef __ADD_H__
#define __ADD_H__

/*This operations does addition*/

//#include "base.h"
#include "op.h"
class Add : public Base {
public:
    Base* inputOne;
    Base* inputTwo;

    Add() : inputOne(), inputTwo() { inputOne = new Op(0.0); inputTwo = new Op(0.0); }
    Add(Base* first, Base* second) : inputOne(first), inputTwo(second) { }

    double evaluate() {
        return inputOne->evaluate() + inputTwo->evaluate();
    }
    std::string stringify() {
        return inputOne->stringify() + " + " + inputTwo->stringify();
    }
};

#endif //__ADD_H__