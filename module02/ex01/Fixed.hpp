# pragma once
# include <iostream>
# include <string>

class Fixed
{
	public:
		Fixed();
		Fixed( int const value );
		Fixed( float const value );
		Fixed( Fixed const & src );
		Fixed &		operator=( Fixed const & rhs );
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
	private:
		int					value;
		static const int	fractionalBits = 8;
};

std::ostream & operator<<(std::ostream &o, Fixed const &n);