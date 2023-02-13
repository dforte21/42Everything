#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <iostream>
#include <exception>
#include <ctime>
#include <cstdlib>

typedef unsigned int	uint;

class Span{
	private:
		std::vector<int>	integer;
		const int			max;
		int					size;
	public:
		Span();
		Span( uint n );
		Span( const Span &c );
		~Span();

		Span	&operator=( const Span &c );

		class maxNumber : public std::exception{
			public:
				virtual const char	*what() const throw(){
					return ("Error:\tMax number reached");
				}
		};
		class noSpan : public std::exception{
			public:
				virtual const char	*what() const throw(){
					return ("Error:\tCannot find span");
				}
		};

		void	addNumber( int _n );
		void	crazyAdd( int _n );
		int		shortestSpan();
		int		longestSpan();
		int		abs( int _n );

		int		getSize();
};

#endif