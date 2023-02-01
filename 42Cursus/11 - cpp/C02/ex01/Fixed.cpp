#include "Fixed.hpp"

Fixed::Fixed ( void ){

	std::cout << "Default constructor called\n";
	this->num = 0;
}

Fixed::Fixed ( const Fixed &copy ){

	std::cout << "Copy constructor called\n";
	*this = copy;
}

Fixed::Fixed( int const intn ){

	std::cout << "Int constructor called\n";
	this->num = intn << this->bit;
}

Fixed::Fixed( float const floatn ){

	std::cout << "Float constructor called\n";
	this->num = (int)(roundf(floatn * (1 << this->bit)));
}

Fixed &Fixed::operator=( const Fixed &copy ){

	std::cout << "Copy assignment operator called\n";
	if (this != &copy)
		this->num = copy.num;
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

float Fixed::toFloat( void ) const{

	return ((float)this->num / (float)(1 << this->bit));
}

int Fixed::toInt( void ) const{

	return (this->num >> this->bit);
}

std::ostream&	operator<<(std::ostream& stream, Fixed const &clas){

	stream << clas.toFloat();
	return (stream);
}