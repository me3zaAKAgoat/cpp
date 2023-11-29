#include "Form.hpp"

#include <iostream>

int main()
{
	try
{
		Bureaucrat *bureaucrat = new Bureaucrat("bureaucrat", 3);
		Form *form = new Form("form", 2, 2);
		form->beSigned(*bureaucrat);
		std::cout << *bureaucrat << std::endl;
		delete bureaucrat;
	}
	catch( std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
{
		Bureaucrat *bureaucrat = new Bureaucrat("bureaucrat", 1);
		Form *form = new Form("form", 2, 2);
		form->beSigned(*bureaucrat);
		std::cout << *bureaucrat << std::endl;
		delete bureaucrat;
	}
	catch( std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}