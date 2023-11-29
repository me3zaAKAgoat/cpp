#pragma once

#include <string>

class WrongAnimal
{
	public:
		WrongAnimal();
		virtual ~WrongAnimal();
		WrongAnimal( WrongAnimal const & src );
		WrongAnimal &		operator=( WrongAnimal const & rhs );
		void	makeSound() const;
		std::string		getType() const;
	protected:
		std::string		type;
};