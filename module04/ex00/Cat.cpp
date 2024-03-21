#include "Cat.hpp"
#include <iostream>

Cat::Cat()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat( Cat const & src ) : Animal(src)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->type = src.type;
}

Cat &	Cat::operator=( Cat const & rhs )
{
	Animal::operator=(rhs);
	std::cout << "Cat assignment operator called" << std::endl;
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}