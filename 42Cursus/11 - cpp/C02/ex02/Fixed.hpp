#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{
	private:
		int num;
		static const int bit = 8;

	public:
		Fixed( void );
		Fixed( const Fixed &copy );
		Fixed( const int intn );
		Fixed( const float floatn );
		~Fixed( void );
		Fixed &operator++();
		Fixed operator++(int);
		Fixed &operator--();
		Fixed operator--(int);
		Fixed &operator=( const Fixed &copy );
		Fixed operator+( const Fixed &copy );
		Fixed operator-( const Fixed &copy );
		Fixed operator*( const Fixed &copy );
		Fixed operator/( const Fixed &copy );
		bool operator<( const Fixed &copy ) const;
		bool operator>( const Fixed &copy ) const;
		bool operator<=( const Fixed &copy ) const;
		bool operator>=( const Fixed &copy ) const;
		bool operator==( const Fixed &copy ) const;
		bool operator!=( const Fixed &copy ) const;
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
		static Fixed &min(Fixed& f1, Fixed& f2);
		static Fixed const &min(Fixed const & f1, Fixed const & f2);
		static Fixed &max(Fixed& f1, Fixed& f2);
		static Fixed const &max(Fixed const & f1, Fixed const & f2);
};

std::ostream&	operator<<(std::ostream& stream, Fixed const &clas);

#endif