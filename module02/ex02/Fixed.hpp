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
		bool operator>(Fixed const &rhs) const;
		bool operator<(Fixed const &rhs) const;
		bool operator>=(Fixed const &rhs) const;
		bool operator<=(Fixed const &rhs) const;
		bool operator==(Fixed const &rhs) const;
		bool operator!=(Fixed const &rhs) const;
		Fixed operator+(Fixed const &rhs) const;
		Fixed operator-(Fixed const &rhs) const;
		Fixed operator*(Fixed const &rhs) const;
		Fixed operator/(Fixed const &rhs) const;
		Fixed operator++();
		Fixed operator--();
		Fixed operator++(int);
		Fixed operator--(int);
		static Fixed const &min(Fixed const &n1, Fixed const &n2);
		static Fixed &min(Fixed &n1, Fixed &n2);
		static Fixed const &max(Fixed const &n1, Fixed const &n2);
		static Fixed &max(Fixed &n1, Fixed &n2);
	
	private:
		int					value;
		static const int	fractionalBits = 8;
};

std::ostream & operator<<(std::ostream &o, Fixed const &n);