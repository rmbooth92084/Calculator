#ifndef __TWOPOW_H__
#define __TWOPOW_H__

/*This operations does 2^()*/

#include "op.h"
class TwoPow : public Base {
public:
    Base* inputOne;

    TwoPow() : inputOne() { inputOne = new Op(0.0); }
    TwoPow(Base* first) : inputOne(first) { }

    double evaluate() {
        return pow(2, inputOne->evaluate());
    }
    std::string stringify() {
        return "2 ^ (" + inputOne->stringify() + ")";
    }
};

#endif //__TWOPOW_H__