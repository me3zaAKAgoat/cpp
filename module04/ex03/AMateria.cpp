#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria() : type("default")
{
	std::cout << "Constructed AMateria" << std::endl;
}

AMateria::AMateria(std::string const & type) : type(type)
{
	std::cout << "Constructed AMateria" << std::endl;
}

AMateria::AMateria(AMateria const & src)
{
	std::cout<< "Copy constructor AMateria" << std::endl;
	*this = src;
}

AMateria::~AMateria()
{
	std::cout << "Destroyed AMateria" << std::endl;
}

AMateria &		AMateria::operator=( AMateria const & rhs )
{
	std::cout << "Assignment operator AMateria" << std::endl;
	if (this != &rhs)
	{
		this->type = rhs.type;
	}
	return (*this);
}

std::string const & AMateria::getType() const
{
	return (this->type);
}

void AMateria::use(ICharacter& target)
{
	(void)target;
}