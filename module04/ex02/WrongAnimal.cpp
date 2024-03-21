#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal( WrongAnimal const & src )
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	this->type = src.type;
}

WrongAnimal &	WrongAnimal::operator=( WrongAnimal const & rhs )
{
	std::cout << "WrongAnimal assignment operator called" << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return *this;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal sound" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return this->type;
}
