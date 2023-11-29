#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap () : ClapTrap(), FragTrap(), ScavTrap()
{
	std::cout << "Constructed DiamondTrap" << std::endl;
}

DiamondTrap::DiamondTrap (std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
	this->name = name;
	this->hp = 100;
	this->ep = 50;
	this->ad = 30;
	std::cout << "Constructed DiamondTrap" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Destroyed DiamondTrap" << std::endl;
}

void DiamondTrap::WhoAmI(void)
{
	std::cout << "My name is " << this->name << " and my ClapTrap name is " << ClapTrap::name << std::endl;
}

DiamondTrap::DiamondTrap( DiamondTrap const & src ) : ClapTrap(src), FragTrap(src), ScavTrap(src)
{
	this->name = src.name;
	std::cout << "Copy constructed DiamondTrap" << std::endl;
}

DiamondTrap &		DiamondTrap::operator=( DiamondTrap const & rhs )
{
	std::cout << "Assigned DiamondTrap" << std::endl;
	if (this != &rhs)
	{
		ClapTrap::name = rhs.name + "_clap_name";
		this->name = rhs.name;
		this->hp = 100;
		this->ep = 50;
		this->ad = 30;
	}
	return *this;
}