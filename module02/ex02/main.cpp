#include "Fixed.hpp"
#include <iostream>

int main( void )
{
	Fixed a ( 2.25f );
	Fixed b ( 2);

	std::cout << "a * b : " << a * b << std::endl;
	return (0);
}