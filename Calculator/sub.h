#ifndef __SUB_H__
#define __SUB_H__

/*This operations does subtraction*/

#include "base.h"
#include "op.h"
class Sub : public Base {
public:
    Base* inputOne;
    Base* inputTwo;

    Sub() : inputOne(), inputTwo() { inputOne = new Op(0.0); inputTwo = new Op(0.0); }
    Sub(Base* first, Base* second) : inputOne(first), inputTwo(second) { }

    double evaluate() {
        return inputOne->evaluate() - inputTwo->evaluate();
    }
    std::string stringify() {
        return inputOne->stringify() + " - " + inputTwo->stringify();
    }
};

#endif //__ADD_H__