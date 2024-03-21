#pragma once

#include <string>

class ClapTrap
{

	public :
		ClapTrap();
		ClapTrap(std::string name);
		~ClapTrap();
		ClapTrap( ClapTrap const & src );
		ClapTrap &operator=( ClapTrap const & rhs );
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
	protected :
		std::string name;
		int hp;
		int ep;
		int ad;

};
