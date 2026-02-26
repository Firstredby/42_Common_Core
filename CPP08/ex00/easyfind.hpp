#pragma once
#include <iostream>
#include <exception>
#include <algorithm>

template <typename T>
	void easyfind (T arr, int val)
{
	typename T::iterator it = std::find(arr.begin(), arr.end(), val);
	if (it == arr.end())
		throw std::out_of_range("No matches found");
	else
		std::cout << "Found: " << *it << std::endl;
}