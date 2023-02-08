#include "Brain.hpp"

Brain::Brain(){
	memset(this->ideas, 0, 100);
	std::cout << "Great, now I have a Brain\n";
}

Brain::Brain(const Brain &copy ){
	*this = copy;
	std::cout << "Great, now I have a Brain\n";
}

Brain::~Brain(){
	std::cout << "I have severe Brain damage\n";
}

Brain	&Brain::operator=( const Brain &copy ){
	if (this != &copy)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = copy.ideas[i];
	}
	return (*this);
}
		
void	Brain::setIdeas(int start, int len, const std::string idea){
	for (int i = start; i < len; i++)
		this->ideas[i] = idea;
}

void	Brain::printIdea( int index ){
	std::cout << "I have an Idea! " << this->ideas[index] << std::endl;
}