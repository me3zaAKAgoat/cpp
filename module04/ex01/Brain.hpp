#pragma once

#include <string>

class Brain
{
	public:
		Brain();
		~Brain();
		Brain( Brain const & src );
		Brain &		operator=( Brain const & rhs );
	private:
		std::string	ideas[100];
};
