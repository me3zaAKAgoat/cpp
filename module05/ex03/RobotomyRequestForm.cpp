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
		std::srand(static_cast<unsigned int>(time(0)));

		unsigned int r = static_cast<double>(std::rand()) / RAND_MAX; 

		if (r > 0.5)
			std::cout << this->target << " could not be robotomized." << std::endl;
		else
			std::cout << this->target << " has been robotomized successfully." << std::endl;
		
	}
}

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
}