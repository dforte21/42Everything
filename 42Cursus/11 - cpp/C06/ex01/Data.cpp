#include "Data.hpp"

Data::Data() : data(0){
	std::cout << "Data constructed\n";
}

Data::Data( int _n ) : data(_n){
	std::cout << "Data constructed\n";
}

Data::Data( const Data &c ){
	*this = c;
	std::cout << "Data constructed\n";
}

Data::~Data(){
	std::cout << "Data destroyed\n";
}

Data	&Data::operator=( const Data &c ){
	if (this != &c)
		this->data = c.getData();
	return (*this);
}

int		Data::getData() const{
	return (this->data);
}

void	Data::setData( int _n ){
	this->data = _n;
}