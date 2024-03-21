#include "RPN.hpp"

RPN::RPN() {
}

RPN::~RPN() {
}

RPN::RPN( RPN const & src ) {
	*this = src;
}

RPN &		RPN::operator=( RPN const & rhs ) {
	if ( this != &rhs ) {
		
	}
	return *this;
}

void RPN::execute(std::string str)
{
	std::stack<int> numbers;
	std::string::iterator it = str.begin();

	while (it != str.end())
	{
		if (*it >= '0' && *it <= '9')
			numbers.push(*it - '0');
		else if (*it == '+' || *it == '-' || *it == '*' || *it == '/' || *it == '%')
		{
			if (numbers.size() < 2)
			{
				std::cerr << "Error: invalid expression" << std::endl;
				return ;
			}
			int b = numbers.top();
			numbers.pop();
			int a = numbers.top();
			numbers.pop();
			if (*it == '+')
				numbers.push(a + b);
			else if (*it == '-')
				numbers.push(a - b);
			else if (*it == '*')
				numbers.push(a * b);
			else if (*it == '/')
			{
				if (b == 0)
				{
					std::cerr << "Error: division by zero" << std::endl;
					return ;
				}
				numbers.push(a / b);
			}
		}
		else if (*it == ' ')
		{
			it++;
			continue ;
		}
		else
		{
			std::cerr << "Error: invalid character" << std::endl;
			return ;
		}
		it++;
	}
	if (numbers.size() != 1)
	{
		std::cerr << "Error: invalid expression" << std::endl;
		return ;
	}
	std::cout << numbers.top() << std::endl;
}

