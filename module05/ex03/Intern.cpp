#include "Intern.hpp"
#include <iostream>

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern( Intern const & src )
{
	*this = src;
}

Intern &		Intern::operator=( Intern const & rhs )
{
	(void)rhs;
	return *this;
}

AForm*			Intern::makeForm(std::string formName, std::string target)
{
    std::string formNameArray[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int i = 0;
	while (i < 3 && formName != formNameArray[i])
		i++;
	switch (i)
	{
		case 0:
			return new ShrubberyCreationForm(target);
		case 1:
			return new RobotomyRequestForm(target);
		case 2:
			return new PresidentialPardonForm(target);
		default:
			throw FormNotFoundException();
	}
}

AForm*			Intern::makePresidentialPardonForm(std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm*			Intern::makeRobotomyRequestForm(std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm*			Intern::makeShrubberyCreationForm(std::string target)
{
	return new ShrubberyCreationForm(target);
}

const char* Intern::FormNotFoundException::what() const throw()
{
	return "Form not found";
}
