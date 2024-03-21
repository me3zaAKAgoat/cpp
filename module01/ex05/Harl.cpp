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
	void (Harl::*f[Harl::NBR_LEVELS])() = {&Harl::info, &Harl::debug, &Harl::error, &Harl::warning};
	std::string levelStrings[Harl::NBR_LEVELS] = {"info", "debug", "error", "warning"};

	int i = 0;
	while (i < NBR_LEVELS)
	{
		if (levelStrings[i] == level)
			(this->*f[i])();
		i++;
	}
}