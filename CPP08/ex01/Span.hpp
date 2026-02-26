#pragma once

#include <algorithm>
#include <exception>
#include <vector>
#include <iostream>

class Span
{
private:
	unsigned int N;
	std::vector<int> numbers;
	Span();
public:
	Span(unsigned int n);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	void addNumber(int number);
	int shortestSpan() const;
	int longestSpan() const;
	template <typename T> void addNumbers(T first, T last)
	{
		while (first != last)
			addNumber(first++);
	}
};

