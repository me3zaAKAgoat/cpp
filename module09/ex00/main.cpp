#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	BitcoinExchange		exchange;

	if (ac != 2)
	{
		std::cerr << "Error: invalid number of arguments" << std::endl;
		return 1;
	}
	try
	{
		exchange.fillDb();
		exchange.executeKeystone(av[1]);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}
	return 0;
}