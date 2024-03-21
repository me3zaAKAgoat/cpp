#include "AForm.hpp"
#include <iostream>

AForm::AForm( std::string name, int gradeToSign, int gradeToExecute ) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm() : name("default"), isSigned(false), gradeToSign(150), gradeToExecute(150)
{
}

AForm::~AForm()
{
}

AForm::AForm( AForm const & src ) : name(src.name), isSigned(src.isSigned), gradeToSign(src.gradeToSign), gradeToExecute(src.gradeToExecute)
{
}

AForm &	AForm::operator=( AForm const & rhs )
{
	if (this != &rhs)
	{
		this->name = rhs.name;
		this->isSigned = rhs.isSigned;
	}
	return *this;
}

std::string	AForm::getName() const
{
	return this->name;
}

bool		AForm::getIsSigned() const
{
	return this->isSigned;
}

int			AForm::getGradeToSign() const
{
	return this->gradeToSign;
}

int			AForm::getGradeToExecute() const
{
	return this->gradeToExecute;
}

void		AForm::beSigned( Bureaucrat & b )
{
	if (b.getGrade() > this->gradeToSign)
		throw AForm::GradeTooLowException();
	else
		this->isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

const char* AForm::NotSignedException::what() const throw()
{
	return "Form is not signed thus I cannot execute it";
}

std::ostream &			operator<<( std::ostream & o, AForm const & i )
{
	o << i.getName() << ", Aform is signed: " << i.getIsSigned() << ", grade to sign: " << i.getGradeToSign() << ", grade to execute: " << i.getGradeToExecute();
	return o;
}