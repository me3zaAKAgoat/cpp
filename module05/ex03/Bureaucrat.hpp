#pragma once

#include <string>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat( std::string const & name, int grade );
		~Bureaucrat();
		Bureaucrat( Bureaucrat const & src );
		Bureaucrat &		operator=( Bureaucrat const & rhs );
		std::string const	getName() const;
		int					getGrade() const;
		void				incrementGrade();
		void				decrementGrade();
		void			signForm(AForm & form);
		void			executeForm(AForm const & form);
		class GradeTooHighException : public std::exception
{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
{
			public:
				virtual const char* what() const throw();
		};
	private:
		std::string 		name;
		int					grade;
};

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i );
