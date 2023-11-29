#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->brain;
}

Dog::Dog( Dog const & src )
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = src;
}

Dog &	Dog::operator=( Dog const & rhs )
{
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &rhs)
	{
		Animal::operator=(rhs);
		delete this->brain;
		this->brain = new Brain(*rhs.brain);
	}
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "Bark" << std::endl;
}