#include "Span.hpp"
#include <stdexcept>

Span::Span()
{
}

Span::Span(unsigned int n) : N(n), numbers()
{
}

Span::Span(const Span& other)
{
	N = other.N;
	numbers = other.numbers;
}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		N = other.N;
		numbers = other.numbers;
	}
	return *this;
}

Span::~Span()
{
}

void Span::addNumber(int number)
{
	if (numbers.size() < N)
		numbers.push_back(number);
	else
		throw std::out_of_range("Cannot add more numbers, capacity reached");
}

int Span::shortestSpan() const
{
	if (numbers.size() < 2)
		throw std::out_of_range("Not enough numbers to find a span");
	std::vector<int> sorted = numbers;
	std::sort(sorted.begin(), sorted.end());
	int min = sorted[1] - sorted[0];
	for (size_t i = 2; i < sorted.size(); i++)
	{
		int diff = sorted[i] - sorted[i - 1];
		if (diff < min)
			min = diff;
	}
	return min;
}

int Span::longestSpan() const
{
	if (numbers.size() < 2)
		throw std::out_of_range("Not enough numbers to find a span");
	std::vector<int> sorted = numbers;
	std::sort(sorted.begin(), sorted.end());
	return sorted[sorted.size() - 1] - sorted[0];
}
