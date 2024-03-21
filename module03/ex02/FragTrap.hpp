#pragma once

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public :
        FragTrap(std::string name);
		FragTrap();
		~FragTrap();
		FragTrap( FragTrap const & src );
		FragTrap &		operator=( FragTrap const & rhs );
        void highFivesGuys(void);
};