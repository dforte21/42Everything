#include "Fixed.hpp"

Fixed::Fixed ( void ){

	//std::co/ut << "Default constructor called\n";
	this->num = 0;
}

Fixed::Fixed ( const Fixed &copy ){

	//std::cout << "Copy constructor called\n";
	*this = copy;
}

Fixed::Fixed( int const intn ){

	//std::cout << "Int constructor called\n";
	this->num = intn << this->bit;
}

Fixed::Fixed( float const floatn ){

	//std::cout << "Float constructor called\n";
	this->num = (int)(roundf(floatn * (1 << this->bit)));
}

Fixed &Fixed::operator=( const Fixed &copy ){

	//std::cout << "Copy assignment operator called\n";
	if (this != &copy)
		this->num = copy.num;
	return (*this);
}

Fixed::~Fixed ( void ){

	//std::cout << "Destructor called\n";
}

Fixed &Fixed::operator++(){

	this->num++;
	return (*this);
}

Fixed Fixed::operator++(int){

	Fixed temp(*this);
	++this->num;
	return (temp);
}

Fixed &Fixed::operator--(){

	this->num--;
	return (*this);
}

Fixed Fixed::operator--(int){

	Fixed temp(*this);
	--this->num;
	return (temp);
}

Fixed Fixed::operator+( const Fixed &copy ){

	Fixed next(*this);

	next.setRawBits(this->getRawBits() + copy.getRawBits());
	return (next);
}

Fixed Fixed::operator-( const Fixed &copy ){
	
	Fixed next(*this);

	next.setRawBits(this->getRawBits() - copy.getRawBits());
	return (next);
}

Fixed Fixed::operator*( const Fixed &copy ){

	Fixed	next(*this);
	long	f;
	long	s;

	f = (long)this->getRawBits();
	s = (long)copy.getRawBits();
	next.setRawBits((f * s) / (1 << Fixed::bit));
	return (next);
}

Fixed Fixed::operator/( const Fixed &copy ){
	
	Fixed next(*this);

	next.setRawBits(this->getRawBits() / copy.getRawBits());
	return (next);
}

bool Fixed::operator<( const Fixed &copy ) const{

	return (this->num < copy.num);
}

bool Fixed::operator>( const Fixed &copy ) const{

	return (this->num > copy.num);
}

bool Fixed::operator<=( const Fixed &copy ) const{

	return (this->num <= copy.num);
}

bool Fixed::operator>=( const Fixed &copy ) const{

	return (this->num >= copy.num);
}

bool Fixed::operator==( const Fixed &copy ) const{

	return (this->num == copy.num);
}

bool Fixed::operator!=( const Fixed &copy ) const{

	return (this->num != copy.num);
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

Fixed &Fixed::min(Fixed& f1, Fixed& f2){

	if ( f1 <= f2 )
		return (f1);
	return (f2);
}

Fixed const &Fixed::min(Fixed const & f1, Fixed const & f2){

	if ( f1 <= f2 )
		return (f1);
	return (f2);
}

Fixed &Fixed::max(Fixed& f1, Fixed& f2){

	if ( f1 >= f2 )
		return (f1);
	return (f2);
}

Fixed const &Fixed::max(Fixed const & f1, Fixed const & f2){

	if ( f1 >= f2 )
		return (f1);
	return (f2);
}

std::ostream&	operator<<(std::ostream& stream, Fixed const &clas){

	stream << clas.toFloat();
	return (stream);
}