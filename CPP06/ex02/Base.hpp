#pragma once

#include <iostream>
#include <stdint.h>
#include <ctime>
#include <cstdlib>

using std::cout;
using std::endl;

class Base
{
public:
	virtual ~Base();

	Base *	generate();
	void	identify(Base* p);
	void	identify(Base& p);
};
