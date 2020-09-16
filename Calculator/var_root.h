#ifndef __VAR_ROOT_H__
#define __VAR_ROOT_H__

#include "op.h"

class VarRoot : public Base {
public:
	Base* inputOne;
	Base* inputTwo;

	VarRoot() : inputOne(), inputTwo() { inputOne = new Op(0.0); inputTwo = new Op(0.0); }
	VarRoot(Base* first, Base* second) : inputOne(first), inputTwo(second) { }
	
	double evaluate() {
		if ((int)inputTwo->evaluate() < 1 || inputOne->evaluate() < 0)
			return 0;
		return pow(inputOne->evaluate(), 1 / inputTwo->evaluate());
	}
	std::string stringify() {
		if ((int)inputTwo->evaluate() < 1 || inputOne->evaluate() < 0)
			return "MATH ERROR";
		return "(" + inputOne->stringify() + ") ^ (1 / " + inputTwo->stringify() + ")";
	}
};

#endif //var_root.h