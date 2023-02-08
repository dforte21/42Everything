#include "Dog.hpp"

Dog::Dog() : Animal(){
	this->type = "Dog";
	std::cout << this->type << " È nato\n";
	this->brain = new Brain();
	this->brain->setIdeas(0, 100, "ossa");
}

Dog::Dog( const Dog &copy ) : Animal(copy){
	this->type = "Dog";
	std::cout << this->type << " È nato\n";
	this->brain = new Brain();
	this->brain->setIdeas(0, 100, "ossa");
}

Dog::~Dog(){
	delete (this->brain);
	std::cout << this->type << " È scappato con l'eredità\n";
}

Dog	&Dog::operator=( const Dog &copy ){
	if (this != &copy)
	{
		this->type = copy.type;
		this->brain = copy.brain;
	}
	return (*this);
}

void	Dog::makeSound() const{
	std::cout << "฿₳Ɽ₭ ฿₳Ɽ₭\n";
}

void	Dog::printIdea( int index ) const{
	this->brain->printIdea(index);
}