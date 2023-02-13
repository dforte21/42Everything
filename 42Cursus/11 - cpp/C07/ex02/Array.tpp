#include "Array.hpp"
 
template <typename A>
Array<A>::Array() : array(NULL), size(0){}

template <typename A>
Array<A>::Array( uint n ) : size(n){
	this->array = new A[size];
}

template <typename A>
Array<A>::Array( const Array &c ){
	*this = c;
}

template <typename A>
Array<A>::~Array(){
	if (this->array)
		delete[] (this->array);
}

template <typename A>
Array<A>	&Array<A>::operator=( const Array &c ){
	if (this == &c)
		return (*this);
	if (this->array)
		delete[] (this->array);
	this->size = c.size;
	this->array = c.array;
	return (*this);
}

template <typename A>
A		Array<A>::getValue( int idx ) const{
	if (this->size <= idx || idx < 0)
		throw Array<A>::outOfBounds();
	return (this->array[idx]);
}

template <typename A>
void	Array<A>::setValue( A value, int idx ) const{
	if (this->size <= idx || idx < 0)
		throw Array<A>::outOfBounds();
	this->array[idx] = value;
}

template <typename A>
int	Array<A>::getSize() const{
	return (this->size);
}
