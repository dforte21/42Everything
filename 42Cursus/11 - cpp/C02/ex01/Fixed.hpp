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
		Fixed &operator=( const Fixed &copy );
		~Fixed( void );
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;

};

std::ostream&	operator<<(std::ostream& stream, Fixed const &clas);

#endif