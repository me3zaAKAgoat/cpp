#include <ScalarConverter.hpp>

int	main(int ac, char *av[])
{
	if (ac != 2)
		return (std::cerr << "bad number of arguments" << std::endl, EXIT_FAILURE);
	ScalarConverter::convert(av[1]);
	return (EXIT_SUCCESS);
}