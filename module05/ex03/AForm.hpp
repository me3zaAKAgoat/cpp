#pragma once

#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
		AForm();
		AForm( std::string name, int gradeToSign, int gradeToExecute );
		virtual ~AForm();
		AForm( AForm const & src );
		AForm &		operator=( AForm const & rhs );
		std::string	getName() const;
		bool		getIsSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;
		void		beSigned( Bureaucrat & b );
		virtual void		execute(Bureaucrat const & executor) const = 0;
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
		class NotSignedException : public std::exception
{
			public:
				virtual const char* what() const throw();
		};		
	protected:
		std::string			name;
		bool				isSigned;
		const int			gradeToSign;
		const int			gradeToExecute;	
};

std::ostream &			operator<<( std::ostream & o, AForm const & i );