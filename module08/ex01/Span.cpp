#include "Span.hpp"
#include <cstdlib>
#include <algorithm>

Span::Span() : N(0) {}

Span::Span(unsigned int n) : N(n)
{};

Span::~Span()
{
};

Span::Span( Span const & src )
{
	*this = src;
}

Span &		Span::operator=( Span const & rhs )
{
	if ( this != &rhs )
	{
		this->N = rhs.N;
		this->numbers = rhs.numbers;
	}
	return *this;
}

void Span::addNumber(int n)
{
	if (numbers.size() == this->N)
		throw std::overflow_error("array is full");
	numbers.push_back(n);
}

int Span::longestSpan()
{
	if (numbers.size() < 2)
		throw std::runtime_error("Not enough elements");
	int min = *std::min_element(numbers.begin(), numbers.end()); 
	int max = *std::max_element(numbers.begin(), numbers.end());
	return max - min;
}

int Span::shortestSpan()
{
	if (numbers.size() < 2)
		throw std::runtime_error("Not enough elements");
	std::sort(numbers.begin(), numbers.end());
	int min = numbers[1] - numbers[0];
	for (unsigned int i = 2; i < numbers.size(); i++)
	{
		if (numbers[i] - numbers[i - 1] < min)
			min = numbers[i] - numbers[i - 1];
	}
	return min;
}

void Span::addMumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (numbers.size() + std::distance(begin, end) > this->N)
		throw std::overflow_error("array is full");
	numbers.insert(numbers.end(), begin, end);
}