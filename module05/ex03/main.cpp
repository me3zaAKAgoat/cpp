#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

#include <iostream>

int main()
{
	Intern someRandomIntern;
	Bureaucrat b("Bureaucrat", 1);
	AForm* rrf;
	AForm* scf;
	AForm* ppf;
	AForm* form;

	try
	{
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		scf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		ppf = someRandomIntern.makeForm("presidential pardon", "Bender");
		form = someRandomIntern.makeForm("presidential pardon", "Bender");
		b.signForm(*rrf);
		b.executeForm(*rrf);
		b.signForm(*scf);
		b.executeForm(*scf);
		b.signForm(*ppf);
		b.executeForm(*ppf);
		b.signForm(*form);
		b.executeForm(*form);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	delete rrf;
	delete scf;
	delete ppf;
	delete form;
	return 0;
}