#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain{
	protected:
		std::string ideas[100];
	public:
		Brain();
		Brain(const Brain &copy );
		~Brain();
		Brain	&operator=( const Brain &copy );
		void	setIdeas(int start, int len, const std::string idea);
		void	printIdea( int index );
};

#endif