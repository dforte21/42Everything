#include "Point.hpp"

Point::Point( void ) : x(0), y(0){

}

Point::Point( const float x2, const float y2 ) : x(x2), y(y2){

}

Point::Point( const Point &copy ){

	*this = copy;
}

Point::~Point( void ){

	//std::cout << "Sayonara\n";
}

Point &Point::operator=( const Point &copy ){

	if (this != &copy)
		return (*new(this) Point(copy.x.toFloat(), copy.y.toFloat()));
	return (*this);
}

bool Point::operator==( const Point &copy ) const{

	if(this->getX() == copy.getX() && this->getY() == this->getY())
		return (true);
	return (false);
}

float Point::getX( void ) const{

	return (this->x.toFloat());
}

float Point::getY( void ) const{

	return (this->y.toFloat());
}

std::ostream&	operator<<(std::ostream& stream, Point const &clas){

	stream << "x: " << clas.getX() << "\ty: " << clas.getY() << std::endl;
	return (stream);
}