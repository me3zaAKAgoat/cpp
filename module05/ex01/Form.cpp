#include "Form.hpp"

#include <iostream>

Form::Form( std::string name, int gradeToSign, int gradeToExecute ) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form() : name("default"), isSigned(false), gradeToSign(150), gradeToExecute(150)
{
}

Form::~Form()
{
}

Form::Form( Form const & src ) : name(src.name), isSigned(src.isSigned), gradeToSign(src.gradeToSign), gradeToExecute(src.gradeToExecute)
{
}

Form &	Form::operator=( Form const & rhs )
{
	if (this != &rhs)
	{
		this->isSigned = rhs.isSigned;
	}
	return *this;
}

std::string	Form::getName() const
{
	return this->name;
}

bool		Form::getIsSigned() const
{
	return this->isSigned;
}

int			Form::getGradeToSign() const
{
	return this->gradeToSign;
}

int			Form::getGradeToExecute() const
{
	return this->gradeToExecute;
}

void		Form::beSigned( Bureaucrat & b )
{
	if (b.getGrade() > this->gradeToSign)
		throw Form::GradeTooLowException();
	else
		this->isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

std::ostream &			operator<<( std::ostream & o, Form const & i )
{
	o << i.getName() << ", form is signed: " << i.getIsSigned() << ", grade to sign: " << i.getGradeToSign() << ", grade to execute: " << i.getGradeToExecute();
	return o;
}