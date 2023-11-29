#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm();
		~ShrubberyCreationForm();
		ShrubberyCreationForm( ShrubberyCreationForm const & src );
		ShrubberyCreationForm &		operator=( ShrubberyCreationForm const & rhs );
		ShrubberyCreationForm( std::string target );
		void		execute(Bureaucrat const & executor) const;
	private:
		std::string	target;
};