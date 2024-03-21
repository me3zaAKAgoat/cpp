#pragma once

#include <stack>
#include <string>
#include <iostream>

class RPN {
	public:
		RPN();
		~RPN();
		RPN( RPN const & src );
		RPN &		operator=( RPN const & rhs );
		void execute(std::string str);
};