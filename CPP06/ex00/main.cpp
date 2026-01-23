#include "ScalarConverter.hpp"

int main(int ac, char *av[])
{
	if (ac != 2)
		return 0;
	ScalarConverter conv;
	conv.convert(av[1]);
}