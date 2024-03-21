#include "Fixed.hpp"

int main(void)
{
	Fixed nbr(26.5f);

	std::cout << nbr.getRawBits() << std::endl;
	std::cout << (1 << 8) << std::endl;
	return 0;
}