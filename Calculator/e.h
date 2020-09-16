#ifndef __e_H__
#define __e_H__

#include "op.h"

class E : public Base {
public:
    Base* inputOne;
    Base* inputTwo;

    E(Base* first) : inputOne(first) { }

    double evaluate() { 
        return pow(2.718282, inputOne->evaluate()); 
    }
    std::string stringify() { 
        return "e ^ (" + inputOne->stringify() + ")"; 
    }
};

#endif