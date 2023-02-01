#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed{
	private:
		int num;
		static const int bit = 8;

	public:
		Fixed( void );
		Fixed( const Fixed &copy );
		Fixed &operator=( const Fixed &copy );
		~Fixed( void );
		int getRawBits( void ) const;
		void setRawBits( int const raw );

};

#endif