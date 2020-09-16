#ifndef __FACTORIAL_H__
#define __FACTORIAL_H__

//#include "base.h"
#include "op.h"
class Factorial : public Base {
private:
	int num;
	int result = 1;
public:
	Base* inputOne;

	Factorial(Base* first) : inputOne(first) { }

	double evaluate() {
		num = (int)inputOne->evaluate();
		if (num == 0)
			return 1;
		else if (num < 0)
			num *= -1;
		for (int i = 1; i <= num; i++)
		{
			result *= i;
		}
		if ((int)inputOne->evaluate() < 0)
			return 1;
		return result;
	}
	std::string stringify() {
		if (inputOne->evaluate() < 1)
			return "1";
		return  "!" + inputOne->stringify();
	}
};

#endif //factorial.h