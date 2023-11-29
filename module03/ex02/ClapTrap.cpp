#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()
{
	std::cout << "Constructed ClapTrap" << std::endl;
};

ClapTrap::ClapTrap(std::string name) : name(name), hp(10), ep(10), ad(0)
{
	std::cout << "Constructed ClapTrap" << std::endl;
};

ClapTrap::~ClapTrap()
{
	std::cout << "Destroyed ClapTrap" << std::endl;
};

ClapTrap::ClapTrap(ClapTrap const &rhs)
{
	this->name = rhs.name;
	this->hp = rhs.hp;
	this->ep = rhs.ep;
	this->ad = rhs.ad;
	std::cout << "Copy constructor ClapTrap" << std::endl;
};

ClapTrap &ClapTrap::operator=( ClapTrap const & rhs )
{
	std::cout << "Assignment operator ClapTrap" << std::endl;
	if (this != &rhs)
	{
		this->name = rhs.name;
		this->hp = rhs.hp;
		this->ep = rhs.ep;
		this->ad = rhs.ad;
	}
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (this->ep == 0)
		return ;
	this->ep--;
	std::cout << "ClapTrap " << this->name << " attacks " << target << " causing " << this->ad << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if ((this->hp - static_cast<int>(amount)) <= 0)
		return ;
	this->hp -= amount;
	std::cout << "ClapTrap has taken " << amount << " hits of damage!" << std::endl; 
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->ep == 0)
		return ;
	this->ep--;
	this->hp += amount;
	std::cout << "ClapTrap has repaired " << amount << " health points!" << std::endl; 
}
