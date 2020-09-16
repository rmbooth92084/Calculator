#ifndef __SQU_ROOT_H__
#define __SQU_ROOT_H__

#include "base.h"

class SquRoot : public Base {


public:
	Base* input;

	SquRoot(Base* num) : input(num) { }

	double evaluate() {
		if (input->evaluate() < 0)
			return 0;
		return sqrt(input->evaluate());
	}
	std::string stringify() {
		if (input->evaluate() < 0)
			return "MATH ERROR";
		return "(" + input->stringify() + ")^(1/2)";
	}
};

#endif //squ_root.h