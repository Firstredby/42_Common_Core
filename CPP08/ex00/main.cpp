#include "easyfind.hpp"
#include <vector>
#include <list>

int main()
{
	std::vector<int> v;
	for (int i = 0; i < 10; i++)
		v.push_back(i);
	std::list<int> l;
	for (int i = 0; i < 10; i++)
		l.push_back(i);
	try
	{
		easyfind(v, 5);
		easyfind(v, 10);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		easyfind(l, 5);
		easyfind(l, 10);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}