#include "Cat.hpp"

Cat::Cat() : Animal(){
	this->type = "Cat";
	std::cout << this->type << " È nato\n";
	this->brain = new Brain();
	this->brain->setIdeas(0, 100, "Topi");
}

Cat::Cat( const Cat &copy ) : Animal(copy){
	this->type = "Cat";
	std::cout << this->type << " È nato\n";
	this->brain = new Brain();
	this->brain->setIdeas(0, 100, "Topi");
}

Cat::~Cat(){
	delete (this->brain);
	std::cout << this->type << " È scappato con l'eredità\n";
}

Cat	&Cat::operator=( const Cat &copy ){
	if (this != &copy)
	{
		this->type = copy.type;
		this->brain = copy.brain;
	}
	return (*this);
}

void	Cat::makeSound() const{
	std::cout << "𝓜𝓮𝓸𝔀\n";
}

void	Cat::printIdea( int index ) const{
	this->brain->printIdea(index);
}