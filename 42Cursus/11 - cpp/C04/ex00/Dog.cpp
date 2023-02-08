#include "Dog.hpp"

Dog::Dog() : Animal(){
	this->type = "Dog";
	std::cout << this->type << " È nato\n";
}

Dog::Dog( const Dog &copy ) : Animal(copy){
	this->type = "Dog";
	std::cout << this->type << " È nato\n";
}

Dog::~Dog(){
	std::cout << this->type << " È scappato con l'eredità\n";
}

Dog	&Dog::operator=( const Dog &copy ){
	if (this != &copy)
		this->type = copy.type;
	return (*this);
}

void	Dog::makeSound() const{
	std::cout << "฿₳Ɽ₭ ฿₳Ɽ₭\n";
}