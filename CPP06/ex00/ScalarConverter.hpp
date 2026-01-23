#pragma once

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <sstream>

using std::cout;
using std::endl;

class ScalarConverter
{
public:
	ScalarConverter();
	ScalarConverter(ScalarConverter&);
	ScalarConverter& operator=(ScalarConverter&);
	~ScalarConverter();

	static void convert(const std::string&);
};
