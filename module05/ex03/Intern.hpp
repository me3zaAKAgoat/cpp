#pragma once

#include <string>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Intern();
		~Intern();
		Intern( Intern const & src );
		Intern &		operator=( Intern const & rhs );
		AForm*			makeForm(std::string formName, std::string target);
		class FormNotFoundException : public std::exception
{
			public:
				virtual const char* what() const throw();
		};
	private:
		AForm*			makePresidentialPardonForm(std::string target);
		AForm*			makeRobotomyRequestForm(std::string target);
		AForm*			makeShrubberyCreationForm(std::string target);
};