#include "Fixed.hpp"

bool Fixed::operator<(Fixed const &rhs) const
{
	return (this->getRawBits() < rhs.getRawBits());
}

bool Fixed::operator>(Fixed const &rhs) const
{
	return (this->getRawBits() > rhs.getRawBits());
}

bool Fixed::operator>=(Fixed const &rhs) const
{
	return (this->getRawBits() >= rhs.getRawBits());
}

bool Fixed::operator<=(Fixed const &rhs) const
{
	return (this->getRawBits() <= rhs.getRawBits());
}

bool Fixed::operator==(Fixed const &rhs) const
{
	return (this->getRawBits() == rhs.getRawBits());
}

bool Fixed::operator!=(Fixed const &rhs) const
{
	return (this->getRawBits() != rhs.getRawBits());
}

Fixed Fixed::operator+(Fixed const &rhs) const
{
	return (Fixed( this->getRawBits() + rhs.getRawBits() ));
}

Fixed Fixed::operator-(Fixed const &rhs) const
{
	return (Fixed( this->getRawBits() - rhs.getRawBits() ));
}

Fixed Fixed::operator*(Fixed const &rhs) const
{
	return (Fixed( static_cast<float>(this->getRawBits() * rhs.getRawBits()) / (1 << (Fixed::fractionalBits * 2)) ));
}

Fixed Fixed::operator/(Fixed const &rhs) const
{
	return (Fixed( this->toFloat() / rhs.toFloat() ));
}

Fixed Fixed::operator++()
{
	this->value++;
	return (*this);
}

Fixed Fixed::operator--()
{
	this->value--;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp( *this );

	this->value++;
	return (tmp);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp( *this );

	this->value--;
	return (tmp);
}

Fixed &Fixed::max(Fixed &n1, Fixed &n2)
{
	if (n1.getRawBits() > n2.getRawBits())
		return (n1);
	return (n2);
}

Fixed &Fixed::min(Fixed &n1, Fixed &n2)
{
	if (n1.getRawBits() < n2.getRawBits())
		return (n1);
	return (n2);
}

Fixed const &Fixed::max(Fixed const &n1, Fixed const &n2)
{
	if (n1.getRawBits() > n2.getRawBits())
		return (n1);
	return (n2);
}

Fixed const &Fixed::min(Fixed const &n1, Fixed const &n2)
{
	if (n1.getRawBits() < n2.getRawBits())
		return (n1);
	return (n2);
}
