# pragma once
# include <iostream>
# include <string>

class Fixed
{
	public:
		Fixed();
		Fixed( Fixed const & src );
		Fixed &		operator=( Fixed const & rhs );
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
	private:
		int					value;
		static const int	fractionalBits = 8;
};
