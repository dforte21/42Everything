#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>
typedef unsigned int	uint;


template <typename A>
class Array{
	private:
		A	*array;
		int	size;
	public:
		Array();
		Array( uint n );
		Array( const Array &c );
		~Array();
		Array	&operator=( const Array &c );

		A		getValue( int idx ) const;
		void	setValue( A value, int idx ) const;
		int	getSize() const;

		class outOfBounds : public std::exception{
			public:
				virtual const char *what() const throw(){
					return ("Error:\tOut of bounds");
				}
		};
};

#include "Array.tpp"

#endif