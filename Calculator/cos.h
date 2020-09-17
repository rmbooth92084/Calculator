#ifndef __cos_H__
#define __cos_H__

/*This operations cos in radians*/

#include "op.h"
class Cos : public Base {
public:
    Base* inputOne;

    Cos() : inputOne() { inputOne = new Op(0.0); }
    Cos(Base* first) : inputOne(first) { }

    double evaluate() {
        return cos(inputOne->evaluate());
    }
    std::string stringify() {
        return "cos(" + inputOne->stringify() + ")";
    }
};

#endif //__COS_H__