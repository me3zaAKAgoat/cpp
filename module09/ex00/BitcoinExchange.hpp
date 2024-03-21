#pragma once

#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <sstream>
#include <cstdlib>
#include <algorithm>

class BitcoinExchange {
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange( BitcoinExchange const & src );
		BitcoinExchange &		operator=( BitcoinExchange const & rhs );
		void	fillDb(void);
		void	executeKeystone(char *av);
	private:
		float	strtof(std::string str);
		int		strtoi(std::string str);
		bool	isLeapYear(int year);
		bool	isValidDay(int year, int month, int day);
		bool	isValidInput(double valueDouble);
		bool	isValidDate(std::string date);
		std::map<std::string, double>	dateToMultiplier;
};