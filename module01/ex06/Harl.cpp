#include "Harl.hpp"
#include <iostream>

void Harl::debug()
{
	std::cout << "this is a debug msg" << std::endl;
}

void Harl::error()
{
	std::cout << "this is an error msg" << std::endl;
}

void Harl::warning()
{
	std::cout << "this is a warning msg" << std::endl;
}

void Harl::info()
{
	std::cout << "this is an info msg" << std::endl;
}

void Harl::complain(std::string level)
{
	std::string levelStrings[4] = {"debug", "info", "warning", "error"};

	int i;
	i = 0;
	while (i < NBR_LEVELS)
	{
		if (levelStrings[i] == level)
			break ;
		i++;
	}
	switch (i)
	{
		case 0:
			this->debug();
		case 1:
			this->info();
		case 2:
			this->warning();
		case 3:
			this->error();
			break ;
		default:
			std::cout << "Invalid level" << std::endl;
	}
}