/*
- store all the multipliers of the csv file in a map

- check if input file is valid
- iterate through each line the input file and check if the line is valid
- if the line is valid, use lower_bound to find the multiplier and multiply
	- error handling needed for this

- util:
	- validation of dates
	- validation of input values
*/

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
}

BitcoinExchange::~BitcoinExchange() {
}

BitcoinExchange::BitcoinExchange( BitcoinExchange const & src ) {
	*this = src;
}

BitcoinExchange &		BitcoinExchange::operator=( BitcoinExchange const & rhs ) {
	if (this != &rhs)
	{
		this->dateToMultiplier = rhs.dateToMultiplier;
	}
	return *this;
}

void	BitcoinExchange::fillDb()
{
	std::ifstream		ifs("data.csv");
	std::string			line;
	std::string			date;
	std::string			multiplier;
	double				multiplierDouble;

	if (!ifs.is_open())
		throw std::runtime_error("Error: could not open file");
	std::getline(ifs, line); // skip first line
	while (std::getline(ifs, line))
	{
		date = line.substr(0, line.find(','));
		multiplier = line.substr(line.find(',') + 1);
		multiplierDouble = BitcoinExchange::strtof(multiplier);
		this->dateToMultiplier[date] = multiplierDouble;
	}
	ifs.close();
}

void	BitcoinExchange::executeKeystone(char *filename)
{
	std::ifstream	ifs(filename);
	std::string		line;
	std::string		date;
	std::string		value;
	double			valueDouble;
	double			multiplier;
	double			result;

	if (!ifs.is_open())
		throw std::runtime_error("Error: could not open file");
	std::getline(ifs, line);
	if (line != "date | value")
		throw std::runtime_error("Error: invalid header");
	while (std::getline(ifs, line))
	{
		date = line.substr(0, line.find('|'));
		date.erase(std::remove(date.begin(), date.end(), ' '), date.end());
		value = line.substr(line.find('|') + 1);
		try {
			valueDouble = BitcoinExchange::strtof(value);
			if (!isValidDate(date) || !isValidInput(valueDouble))
				continue ;
			std::map<std::string, double>::iterator it = this->dateToMultiplier.lower_bound(date);
			if (it->first == this->dateToMultiplier.end()->first)
				it--;
			multiplier = it->second;
			result = valueDouble * multiplier;
			std::cout << date << " => " << valueDouble << " = " << result << std::endl;
		}
		catch(const std::exception& e) 
		{
			std::cerr << e.what() << std::endl;
		}
	}
}

bool	BitcoinExchange::isValidInput(double valueDouble)
{
	if (valueDouble >= 0 && valueDouble <= 1000)
		return true;
	std::cerr << "Error: invalid value" << std::endl;
	return false;
}

/* missing precision */
bool	BitcoinExchange::isLeapYear(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool	BitcoinExchange::isValidDay(int year, int month, int day)
{
	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (isLeapYear(year))
		daysInMonth[1] = 29;
	if (day < 1 || day > daysInMonth[month - 1])
		return false;
	return true;
}

bool	BitcoinExchange::isValidDate(std::string date)
{
	size_t firstDash = date.find('-');
	size_t secondDash = date.find('-', firstDash + 1);

	std::string yearStr = date.substr(0, firstDash);
	std::string monthStr = date.substr(firstDash + 1, secondDash - firstDash - 1);
	std::string dayStr = date.substr(secondDash + 1);


	try {
		int year = BitcoinExchange::strtoi(yearStr);
		int month = BitcoinExchange::strtoi(monthStr);
		int day = BitcoinExchange::strtoi(dayStr);
		if ((month < 1 || month > 12) || !isValidDay(year, month, day) || year < 2009 || (year == 2009 && month == 1 && day == 1))
		{
			std::cerr << "Error: invalid date" << std::endl;
			return false;
		}
		return true;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return false;
	}
}

int		BitcoinExchange::strtoi(std::string str)
{
	std::stringstream ss(str);
	int n;
	ss >> n;
	if (ss.fail() || !ss.eof())
		throw std::runtime_error("Error: invalid int");
	return n;
}

float	BitcoinExchange::strtof(std::string str)
{
	std::stringstream ss(str);
	float n;
	ss >> n;
	if (ss.fail() || !ss.eof())
		throw std::runtime_error("Error: invalid float");
	return n;
}