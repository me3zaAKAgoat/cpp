#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog( Dog const & src ) : Animal(src)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->type = src.type;
}

Dog &	Dog::operator=( Dog const & rhs )
{
	Animal::operator=(rhs);
	std::cout << "Dog assignment operator called" << std::endl;
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "Bark" << std::endl;
}