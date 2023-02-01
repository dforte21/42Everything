#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point{
	private:
		Fixed const x;
		Fixed const y;

	public:
		Point( void );
		Point( const float x2, const float y2 );
		Point( const Point &copy );
		~Point( void );
		Point &operator=( const Point &copy );
		bool operator==( const Point &copy ) const;
		float getX( void ) const;
		float getY( void ) const;
};

std::ostream&	operator<<(std::ostream& stream, Point const &clas);

#endif