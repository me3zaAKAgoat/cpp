#include "Character.hpp"

#include <iostream>

Character::Character() : name("Default")
{
	std::cout << "Constructed Character" << std::endl;
	this->Ihaveaids = new AMateria*[1];
	this->length = 1;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::Character(std::string const & name) : name(name)
{
	std::cout << "Constructed Character" << std::endl;
	this->Ihaveaids = new AMateria*[1];
	this->length = 1;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::Character( Character const & src )
{
	std::cout<< "Copy constructor Character" << std::endl;
	*this = src;
}

Character::~Character()
{
	std::cout << "Destroyed Character" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < this->length; j++)
			if (this->inventory[i] == this->Ihaveaids[j])
				this->Ihaveaids[j] = NULL;
	}
	for (size_t i = 0; i < this->length; i++)
	{
		delete this->Ihaveaids[i];
		void	*tmp = this->Ihaveaids[i];
		for (size_t j = 0; j < this->length; j++)
			if (this->Ihaveaids[j] == tmp)
				this->Ihaveaids[j] = NULL;
	}
	delete [] this->Ihaveaids;
	for (int i = 0; i < 4; i++)
	{
		delete this->inventory[i];
		void	*tmp = this->inventory[i];
		for (size_t j = 0; j < 4; j++)
			if (this->inventory[j] == tmp)
				this->inventory[j] = NULL;
	}
}

Character &		Character::operator=( Character const & rhs )
{
	std::cout << "Assignment operator Character" << std::endl;
	if (this != &rhs)
	{
		this->name = rhs.name;
		for (int i = 0; i < 4; i++)
			delete this->inventory[i];
		for (int i = 0; i < 4; i++)
			if (rhs.inventory[i])
				this->inventory[i] = rhs.inventory[i]->clone();
	}
	return (*this);
}

std::string const & Character::getName() const
{
	return (this->name);
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
		if (!this->inventory[i])
		{
			this->inventory[i] = m;
			return ;
		}
	delete m;
}

void	Character::expandIhaveaids()
{
	AMateria **newIhaveaids = new AMateria*[this->length + 1];
	for (size_t i = 0; i < this->length; i++)
		newIhaveaids[i] = this->Ihaveaids[i];
	delete [] this->Ihaveaids;
	this->length++;
	this->Ihaveaids = newIhaveaids;
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && this->inventory[idx])
	{
		expandIhaveaids();
		this->Ihaveaids[this->length - 1] = this->inventory[idx];
		this->inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && this->inventory[idx])
		this->inventory[idx]->use(target);
}
