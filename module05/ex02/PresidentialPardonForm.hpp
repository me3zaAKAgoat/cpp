#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm();
		~PresidentialPardonForm();
		PresidentialPardonForm( PresidentialPardonForm const & src );
		PresidentialPardonForm &		operator=( PresidentialPardonForm const & rhs );
		PresidentialPardonForm( std::string target );
		void		execute(Bureaucrat const & executor) const;
	private:
		std::string	target;
};