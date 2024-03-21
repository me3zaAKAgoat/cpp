#include "Fixed.hpp"

Fixed::Fixed()
{
	this->value = 0;
}

Fixed::Fixed( const Fixed& src )
{
	this->value = src.getRawBits();
}

Fixed::Fixed( float const f) : value(f * (1 << Fixed::fractionalBits))
{
}

Fixed::Fixed( int const i ) : value(i << fractionalBits)
{
}

Fixed::~Fixed()
{
}


Fixed&	Fixed::operator=( Fixed const& rhs )
{
	if ( this != &rhs )
	{
		this->value = rhs.getRawBits();
	}
	return *this;
}

int	Fixed::getRawBits( void ) const
{
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