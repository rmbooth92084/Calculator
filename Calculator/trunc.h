#ifndef _TRUNC_H_
#define _TRUNC_H_
/*
* This decorator only modifies the stringify funciton to truncate/simplify
* the portiion of the section that it's put around
*/
#include "decorator.h"

class Trunc : public Decorator
{

public:
	Base* input;

	Trunc(Base* expres) : input(expres) { }

	std::string stringify()
	{
		return "" + std::to_string(input->evaluate());
	}
};
#endif //trunc.h