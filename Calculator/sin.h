#ifndef __SIN_H__
#define __SIN_H__

/*This operations sin in radians*/

#include "op.h"
class Sin : public Base {
public:
    Base* inputOne;

    Sin() : inputOne() { inputOne = new Op(0.0); }
    Sin(Base* first) : inputOne(first) { }

    double evaluate() {
        return sin(inputOne->evaluate());
    }
    std::string stringify() {
        return "sin(" + inputOne->stringify() + ")";
    }
};

#endif //__SIN_H__