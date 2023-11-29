#pragma once

#include "Animal.hpp"
#include <string>

class Cat : public Animal
{
	public:
		Cat();
		~Cat();
		Cat( Cat const & src );
		Cat &		operator=( Cat const & rhs );
		void	makeSound() const;
	private:
		Brain	*brain;
};