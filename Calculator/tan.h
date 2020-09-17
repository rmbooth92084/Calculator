#ifndef __TAN_H__
#define __TAN_H__

/*This operations tan in radians*/

#include "op.h"
class Tan : public Base {
public:
    Base* inputOne;

    Tan() : inputOne() { inputOne = new Op(0.0); }
    Tan(Base* first) : inputOne(first) { }

    double evaluate() {
        return tan(inputOne->evaluate());
    }
    std::string stringify() {
        return "tan(" + inputOne->stringify() + ")";
    }
};

#endif //__TAN_H__