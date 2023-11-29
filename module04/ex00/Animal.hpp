#pragma once

#include <string>

class Animal
{
	public:
		Animal();
		virtual ~Animal();
		Animal( Animal const & src );
		Animal &		operator=( Animal const & rhs );
		virtual void	makeSound() const;
		std::string		getType() const;
	protected:
		std::string		type;
};