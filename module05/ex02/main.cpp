#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

#include <iostream>

int main()
{
	try 
	{
		AForm *a = new PresidentialPardonForm("ahmad");
		AForm *b = new ShrubberyCreationForm("tree");
		AForm *c = new RobotomyRequestForm("machine");

		Bureaucrat *bureaucrat = new Bureaucrat("bureaucrat", 3);

		a->beSigned(*bureaucrat);
		a->execute(*bureaucrat);
		b->beSigned(*bureaucrat);
		b->execute(*bureaucrat);
		c->beSigned(*bureaucrat);
		c->execute(*bureaucrat);

		delete a;
		delete b;
		delete c;
		delete bureaucrat;
	}
	catch( std::exception &e )
	{
		std::cout << e.what() << std::endl;
	}
}