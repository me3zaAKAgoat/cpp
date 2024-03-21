#include "Bureaucrat.hpp"

#include <iostream>

int main()
{
	Bureaucrat *bureaucrat;
	try
	{
		bureaucrat = new Bureaucrat("bureaucrat", 150);
		std::cout << *bureaucrat << std::endl;
		delete bureaucrat;
	}
	catch( std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		bureaucrat = new Bureaucrat("bureaucrat", 160);
		std::cout << *bureaucrat << std::endl;
		delete bureaucrat;
	}
	catch( std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}