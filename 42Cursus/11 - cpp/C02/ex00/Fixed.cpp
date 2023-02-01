#include "Fixed.hpp"

Fixed::Fixed ( void ){

	std::cout << "Default constructor called\n";
	this->num = 0;
}

Fixed::Fixed ( const Fixed &copy ){

	std::cout << "Copy constructor called\n";
	*this = copy;
}

Fixed &Fixed::operator=( const Fixed &copy ){

	std::cout << "Copy assignment operator called\n";
	this->num = copy.getRawBits();
	return (*this);
}

Fixed::~Fixed ( void ){

	std::cout << "Destructor called\n";
}

int Fixed::getRawBits( void ) const{

	std::cout << "getRawBits member function called\n";
	return (this->num);
}

void Fixed::setRawBits( int const raw ){

	std::cout << "setRawBits member function called\n";
	this->num = raw;
}