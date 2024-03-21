#pragma once

#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form();
		Form( std::string name, int gradeToSign, int gradeToExecute );
		~Form();
		Form( Form const & src );
		Form &		operator=( Form const & rhs );
		std::string	getName() const;
		bool		getIsSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;
		void		beSigned( Bureaucrat & b );
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
		std::string			name;
		bool				isSigned;
		const int			gradeToSign;
		const int			gradeToExecute;	
};

std::ostream &			operator<<( std::ostream & o, Form const & i );