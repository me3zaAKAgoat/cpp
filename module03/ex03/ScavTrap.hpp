#pragma once

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
    public :
        ScavTrap(std::string name);
		ScavTrap();
		~ScavTrap();
		ScavTrap( ScavTrap const & src );
		ScavTrap &		operator=( ScavTrap const & rhs );
        void attack(const std::string& target);
        void guardGate();
};
