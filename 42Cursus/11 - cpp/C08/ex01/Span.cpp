#include "Span.hpp"

Span::Span() : max(0), size(0){}

Span::Span( uint n ) : max(n), size(0){}

Span::Span( const Span &c ) : max(c.max), size(0){
	*this = c;
}

Span::~Span(){}

Span	&Span::operator=( const Span &c ){
	if (this == &c)
		return (*this);
	this->size = c.size;
	this->integer = c.integer;
	return (*this);
}

void	Span::addNumber( int _n ){
	if (size >= max)
		throw(maxNumber());

	this->integer.push_back(_n);
	this->size++;
}

int		Span::shortestSpan(){
	if (!size || size == 1)
		throw(noSpan());

	std::vector<int>::iterator n1 = integer.begin();
	std::vector<int>::iterator n2;
	int min = *(std::max_element(integer.begin(), integer.end()));

	for (int i = 0; i < size; i++)
	{
		n2 = n1;
		n1++;
		if ((abs(*n2 - *n1)) < min)
			min = abs(*n2 - *n1);
	}
	return (min);
}

int		Span::longestSpan(){
	if (!size || size == 1)
		throw(noSpan());
	std::vector<int>::iterator min = std::min_element(integer.begin(), integer.end());
	std::vector<int>::iterator max = std::max_element(integer.begin(), integer.end());

	return (*max - *min);
}

int		Span::abs( int _n ){
	return((_n < 0) ? -_n : _n);
}

void	Span::crazyAdd( int _n ){
	std::vector<int> tmp;

	srand(time(NULL));
	tmp.reserve(_n);
	for (int i = 0; i < _n; i++)
		tmp.push_back(rand()% 1000);
	if ((size + _n) > max)
		throw(maxNumber());
	size += _n;
	integer.insert(integer.begin(), tmp.begin(), tmp.end());
}

int		Span::getSize(){
	return (size);
}