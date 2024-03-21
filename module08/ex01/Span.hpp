#pragma once
#include <vector>

class Span {
	public:
		Span();
		Span(unsigned int n);
		~Span();
		Span( Span const & src );
		Span &		operator=( Span const & rhs );
		void addNumber(int n);
		void addMumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int shortestSpan();
		int longestSpan();
	private:
		unsigned int N;
		std::vector<int> numbers;
};