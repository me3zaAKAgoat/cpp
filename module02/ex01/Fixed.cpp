#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

Fixed::Fixed( const Fixed& src )
{
	std::cout << "Copy constructor called" << std::endl;
	this->value = src.getRawBits();
}

Fixed::Fixed( float const f) : value(f * (1 << Fixed::fractionalBits))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed( int const i ) : value(i << fractionalBits)
{
	std::cout << "Integer constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=( Fixed const& rhs )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if ( this != &rhs )
	{
		this->value = rhs.getRawBits();
	}
	return *this;
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->value;
}

void Fixed::setRawBits( int const raw )
{
	this->value = raw;
}

float Fixed::toFloat( void ) const
{
	return static_cast<float>(this->value) / (1 << Fixed::fractionalBits);
}

int Fixed::toInt( void ) const
{
	return (this->value >> Fixed::fractionalBits);
}

std::ostream & operator<<(std::ostream &o, Fixed const &n)
{
	o << n.toFloat();
	return o;
}