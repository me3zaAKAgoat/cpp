#include "Ice.hpp"

#include <iostream>

Ice::Ice() : AMateria("ice")
{
	std::cout << "Constructed Ice" << std::endl;
}

Ice::Ice( Ice const & src )
{
	std::cout<< "Copy constructor Ice" << std::endl;
	*this = src;
}

Ice::~Ice()
{
	std::cout << "Destroyed Ice" << std::endl;
}

Ice &		Ice::operator=( Ice const & rhs )
{
	std::cout << "Assignment operator Ice" << std::endl;
	if (this != &rhs)
	{
		this->type = rhs.type;
	}
	return (*this);
}

AMateria* Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}