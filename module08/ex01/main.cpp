#include "Span.hpp"
#include <iostream>

int main()
{
	try {
		Span sp = Span(5);
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

		int arr[] = {1, 2, 3, 4, 5};
		std::vector<int> myVector(arr, arr + sizeof(arr) / sizeof(arr[0]));
		Span sp2 = Span(5);
		sp2.addMumbers(myVector.begin(), myVector.end());
		std::cout << sp2.shortestSpan() << std::endl;
		std::cout << sp2.longestSpan() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}