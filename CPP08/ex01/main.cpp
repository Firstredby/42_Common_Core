#include "Span.hpp"
#include <iostream>

int main()
{
	std::cout << "         Default test" << std::endl
			  << "==============================" << std::endl;
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout  << "shortest span is: "<< sp.shortestSpan() << std::endl;
		std::cout  << "longest span is: "<< sp.longestSpan() << std::endl;
	}
	std::cout << "==============================\n" << std::endl;
	std::cout << "        Overflow test" << std::endl
			  << "==============================" << std::endl;
	{
		Span a = Span(5);
		for (size_t i = 0; i < 6; i++)
		{
			try
			{
				a.addNumber(i);
			}
			catch (std::exception &e)
			{
				std::cerr << e.what() << std::endl;
			}
		}
		std::cout << "shortest span is: " << a.shortestSpan() << std::endl;
		std::cout << "longest span is: " << a.longestSpan() << std::endl;
	}
	std::cout << "==============================\n" << std::endl;
	std::cout << "    Not enough numbers test" << std::endl
			  << "==============================" << std::endl;
	{
		Span a = Span(5);
		a.addNumber(1);
		try
		{
			std::cout << "shortest span is: " << a.shortestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << std::endl << e.what() << std::endl;
		}
		try
		{
			std::cout << "longest span is: " << a.longestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << std::endl << e.what() << std::endl;
		}
	}
	std::cout << "==============================\n" << std::endl;
	std::cout << "      10000 numbers test" << std::endl
			  << "==============================" << std::endl;
	{
		Span a = Span(10000);
		a.addNumbers(0, 10000);
		std::cout << "shortest span is: " << a.shortestSpan() << std::endl;
		std::cout << "longest span is: " << a.longestSpan() << std::endl;
	}
	std::cout << "==============================" << std::endl;
	return 0;
}