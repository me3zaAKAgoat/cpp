#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

bool	isInteger(std::string str)
{
	size_t i = 0;

	if (str[i] == '-' || str[i] == '+')
		i++;
	while (i < str.length())
	{
		if (!std::isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	isFloat(std::string str)
{
	size_t i = 0;
	bool dot = false;

	if (str[i] == '-' || str[i] == '+')
		i++;
	while (i < str.length())
	{
		if (str[i] == '.')
		{
			if (dot)
				return (false);
			dot = true;
		}
		else if (!std::isdigit(str[i]) && str[i] != 'f')
			return (false);
		i++;
	}
	if (str[str.length() - 1] != 'f')
		return (false);
	return (true);
}

bool	isDouble(std::string str)
{
	size_t i = 0;
	bool dot = false;

	if (str[i] == '-' || str[i] == '+')
		i++;
	while (i < str.length())
	{
		if (str[i] == '.')
		{
			if (dot)
				return (false);
			dot = true;
		}
		else if (!std::isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

void	printInt(int i)
{
	std::cout << "char: ";
	if (i < 32 || i > 126)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void	printFloat(float f)
{
	std::cout << "char: ";
	if (f < 32 || f > 126)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
	std::cout << "int: ";
	if (f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min())
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(f) << std::endl;
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void	printDouble(double d)
{
	std::cout << "char: ";
	if (d < 32 || d > 126)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
	std::cout << "int: ";
	if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(d) << std::endl;
	std::cout << "float: ";
	if (d > std::numeric_limits<float>::max() || d < std::numeric_limits<float>::min())
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: " << d << std::endl;

}

void ScalarConverter::convert(char *str)
{
	std::string input = str;
	if (input == "nan" || input == "nanf" || input == "-inf" || input == "+inf" || input == "-inff" || input == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << input << std::endl;
		std::cout << "double: " << input << std::endl;
		return ;
	}
	if (isInteger(input))
		printInt(std::atoi(input.c_str()));
	else if (isFloat(input))
		printFloat(std::atof(input.c_str()));
	else if (isDouble(input))
		printDouble(std::atof(input.c_str()));
	else
		std::cout << "Invalid input" << std::endl;
}