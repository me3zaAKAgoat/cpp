#pragma once

#include "AMateria.hpp"
#include "Character.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		~Ice();
		Ice( Ice const & src );
		Ice &		operator=( Ice const & rhs );
		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
};