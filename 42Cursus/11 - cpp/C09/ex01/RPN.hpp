#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>
#include <exception>
#include <cstdlib>

class RPN{
	private:
		std::stack<int>		numbers;
		std::stack<char>	operands;
	public:
		RPN();
		RPN( std::string &expr );
		RPN( const RPN &c );
		~RPN();

		RPN	&operator=( const RPN &c );

		void	printSolution();

		class invalidExpression : public std::exception{
			virtual const char *what() const throw(){
				return ("Error: Invalid expression, [n1 n2 o1 n3 o2...]\n");
			}
		};
};

#endif