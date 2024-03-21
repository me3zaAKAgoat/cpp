#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat()
{
	std::cout << "WrongCat default constructor called" << std::endl;
	this->type = "WrongCat";
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat( WrongCat const & src ) : WrongAnimal(src)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	this->type = src.type;
}

WrongCat &	WrongCat::operator=( WrongCat const & rhs )
{
	WrongAnimal::operator=(rhs);
	std::cout << "WrongCat assignment operator called" << std::endl;
	return *this;
}

void	WrongCat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}