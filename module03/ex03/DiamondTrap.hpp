#pragma once

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
    private:
        std::string name;
    public:
        DiamondTrap(std::string name);
		DiamondTrap();
		~DiamondTrap();
		DiamondTrap( DiamondTrap const & src );
		DiamondTrap &		operator=( DiamondTrap const & rhs );
        using ScavTrap::attack;
        void WhoAmI(void);
};
