#ifndef __OP_HPP__
#define __OP_HPP__
/*These are the numbers that are used in the operations*/
#include "base.h"

class Op : public Base {
public:
    double temp = 0.0;
    Op() : Base() { temp = 0.0; }

    Op(double value) : Base() { temp = value; }
    virtual double evaluate() { return temp; }
    virtual std::string stringify() { return std::to_string(temp); }
};
#endif //__OP_HPP__