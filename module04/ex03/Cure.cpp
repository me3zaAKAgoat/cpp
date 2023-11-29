#include "Cure.hpp"

#include <iostream>

Cure::Cure() : AMateria("cure")
{
	std::cout << "Constructed Cure" << std::endl;
}

Cure::Cure( Cure const & src )
{
	std::cout<< "Copy constructor Cure" << std::endl;
	*this = src;
}

Cure::~Cure()
{
	std::cout << "Destroyed Cure" << std::endl;
}

Cure &		Cure::operator=( Cure const & rhs )
{
	std::cout << "Assignment operator Cure" << std::endl;
	if (this != &rhs)
	{
		this->type = rhs.type;
	}
	return (*this);
}

AMateria* Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}