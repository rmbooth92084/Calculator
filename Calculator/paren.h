#ifndef _PAREN_H_
#define _PAREN_H_
/*
* This one adds parenthisis around the indicated part of the problem
*/
#include "decorator.h"

class Paren : public Decorator
{
public:
	Base* input;
	
	Paren(Base* expres) : input(expres) { }
	
	std::string stringify(){
		return "(" + input->stringify() + ")";
	}
};
#endif //paren.h