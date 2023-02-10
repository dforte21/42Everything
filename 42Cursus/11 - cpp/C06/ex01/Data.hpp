#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

class Data{
	private:
		int data;
	public:
		Data();
		Data( int _n );
		Data( const Data &c );
		~Data();
		Data	&operator=( const Data &c );

		int		getData() const;
		void	setData( int _n );
};

#endif