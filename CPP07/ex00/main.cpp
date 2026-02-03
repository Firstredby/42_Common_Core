#include "whatever.hpp"
#include <iostream>

using std::cout;
using std::endl;

int	main()
{
	int a = 10;
	int b = 20;

	cout << "before swap: " << "a = " << a
		 << ", b = " << b << endl;
	::swap(a, b);
	cout << "after swap: " << "a = " << a
		 << ", b = " << b << endl;

	cout << "min(a, b) = " << ::min(a, b) << endl;
	cout << "max(a, b) = " << ::max(a, b) << endl;

	std::string str1 = "Hello";
	std::string str2 = "World";

	cout << "before swap: " << "str1 = " << str1
		 << ", str2 = " << str2 << endl;
	::swap(str1, str2);
	cout << "after swap: " << "str1 = " << str1
		 << ", str2 = " << str2 << endl;
	cout << "min(str1, str2) = " << ::min(str1, str2) << endl;
	cout << "max(str1, str2) = " << ::max(str1, str2) << endl;

	return 0;
}