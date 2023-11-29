#pragma once

#include "WrongAnimal.hpp"
#include <string>

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		~WrongCat();
		WrongCat( WrongCat const & src );
		WrongCat &		operator=( WrongCat const & rhs );
		void	makeSound() const;
};