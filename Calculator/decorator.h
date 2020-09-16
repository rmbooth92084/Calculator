#ifndef _DECORATOR_H_
#define _DECORATOR_H_

#include <iostream>
#include "op.h"

class Decorator : public Base {
public:
	Decorator() {};
	double evaluate() { return 0.0; };
	std::string stringify() { return ""; };
};

#endif //decorator.h