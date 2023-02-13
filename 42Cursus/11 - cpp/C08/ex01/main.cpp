#include "Span.hpp"

int main()
{
	{
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		
		try{
			sp.addNumber(12);
		}
		catch(std::exception &e){
			std::cerr << e.what() << std::endl;
		}
	}
	{
		Span sp = Span(100);

		try{
			sp.crazyAdd(100);
			std::cout << std::endl << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
			std::cout << "size:\t" << sp.getSize() << std::endl;
		}
		catch(std::exception &e){
			std::cerr << e.what() << std::endl;
		}
	}
	{
		Span sp = Span(100);

		try{
			sp.crazyAdd(1000);
			std::cout << std::endl << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
			std::cout << "size:\t" << sp.getSize() << std::endl;
		}
		catch(std::exception &e){
			std::cerr << std::endl << e.what() << std::endl;
		}
	}
	return (0);
}