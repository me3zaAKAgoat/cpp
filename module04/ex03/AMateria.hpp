#pragma once

#include <string>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string type;
	public:
		AMateria(std::string const & type);
		AMateria();
		AMateria(AMateria const & src);
		virtual ~AMateria();
		AMateria &		operator=( AMateria const & rhs );
		std::string const & getType() const; 
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};