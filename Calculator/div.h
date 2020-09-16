#ifndef __DIV_H__
#define __DIV_H__

/*This operations does division*/

#include "op.h"
class Div : public Base {
public:
    Base* inputOne;
    Base* inputTwo;

    Div() : inputOne(), inputTwo() { inputOne = new Op(0.0); inputTwo = new Op(0.0); }
    Div(Base* first, Base* second) : inputOne(first), inputTwo(second) { }

    double evaluate() {
        return inputOne->evaluate() / inputTwo->evaluate();
    }
    std::string stringify() {
        return inputOne->stringify() + " / " + inputTwo->stringify();
    }
};

#endif //__ADD_H__