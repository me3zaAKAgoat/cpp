#pragma once

#include "Animal.hpp"
#include <string>

class Dog : public Animal
{
	public:
		Dog();
		~Dog();
		Dog( Dog const & src );
		Dog &		operator=( Dog const & rhs );
		void	makeSound() const;
};