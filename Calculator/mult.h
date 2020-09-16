#ifndef __MULT_H__
#define __MULT_H__

/*This operations does multiplication*/

//#include "base.h"
#include "op.h"
class Mult : public Base {
public:
    Base* inputOne;
    Base* inputTwo;

    Mult() : inputOne(), inputTwo() { inputOne = new Op(0.0); inputTwo = new Op(0.0); }
    Mult(Base* first, Base* second) : inputOne(first), inputTwo(second) { }

    double evaluate() { 
        return inputOne->evaluate() * inputTwo->evaluate();
    }
    std::string stringify() { 
        return inputOne->stringify() + " * " + inputTwo->stringify(); 
    }
};

#endif //__MULT_HPP__