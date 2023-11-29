#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "Constructed ScavTrap" << std::endl;
};

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->hp = 100;
	this->ep = 50;
	this->ad = 20;
	
	std::cout << "Constructed ScavTrap" << std::endl;
};

ScavTrap::~ScavTrap()
{
	std::cout << "Destroyed ScavTrap" << std::endl;
};

void ScavTrap::attack(const std::string& target)
{
	if (this->ep == 0)
		return ;
	this->ep--;
	std::cout << "ScavTrap " << this->name << " attacks " << target << " causing " << this->ad << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->name << " has entered in Gate keeper mode." << std::endl;
}

ScavTrap::ScavTrap( ScavTrap const & src ) : ClapTrap(src)
{
	std::cout << "Copy constructed ScavTrap" << std::endl;
}

ScavTrap &		ScavTrap::operator=( ScavTrap const & rhs )
{
	std::cout << "Assigned ScavTrap" << std::endl;
	if (this != &rhs)
	{
		this->name = rhs.name;
		this->hp = rhs.hp;
		this->ep = rhs.ep;
		this->ad = rhs.ad;
	}
	return *this;
}