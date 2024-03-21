#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>


#include <iostream>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("default")
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & src ) : AForm(src), target(src.target)
{
	*this = src;
}

RobotomyRequestForm &	RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
{
	if (this != &rhs)
	{
		this->target = rhs.target;
	}
	return *this;
}

void		RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	else if (!this->getIsSigned())
		throw AForm::NotSignedException();
	else
	{
		std::srand(time(0));

		int r = std::rand(); 

		if (r % 2 == 0)
			std::cout << this->target << " could not be robotomized." << std::endl;
		else
			std::cout << this->target << " has been robotomized successfully." << std::endl;
		
	}
}

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
}