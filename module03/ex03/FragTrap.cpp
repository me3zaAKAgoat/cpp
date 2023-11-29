#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "constructed FragTrap" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->hp = 100;
    this->ep = 100;
    this->ad = 30;

    std::cout << "constructed FragTrap" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "Destroyed FragTrap" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->name << " high fives you :D" << std::endl;
}

FragTrap::FragTrap( FragTrap const & src ) : ClapTrap(src)
{
	std::cout << "Copy constructed FragTrap" << std::endl;
}

FragTrap &		FragTrap::operator=( FragTrap const & rhs )
{
	std::cout << "Assigned FragTrap" << std::endl;
	if (this != &rhs)
	{
		this->name = rhs.name;
		this->hp = rhs.hp;
		this->ep = rhs.ep;
		this->ad = rhs.ad;
	}
	return *this;
}