#ifndef _ABS_H_
#define _ABS_H_
/*
* This decorator only modifies the evalutae function to find the absolute of it
*/
#include "decorator.h"

class Abs : public Decorator {
public:

	Base* input;

	Abs(Base* first) : input(first) {};
	
	double evaluate() { 
		return abs(input->evaluate());
	}


};

#endif //abs.h