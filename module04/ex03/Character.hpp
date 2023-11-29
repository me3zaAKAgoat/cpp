#pragma once

#include <string>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
	public:
		Character();
		Character(std::string const & name);
		~Character();
		Character( Character const & src );
		Character &		operator=( Character const & rhs );
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
	private:
		std::string name;
		AMateria *inventory[4];
		void	expandIhaveaids(void);
		AMateria **Ihaveaids;
		size_t length;
};
