#pragma once

#include <string>

class Harl
{
	public:
		static const int NBR_LEVELS = 4;
		void complain(std::string leve);
	private:
		void debug();
		void info();
		void warning();
		void error();
};