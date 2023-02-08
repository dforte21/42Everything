#include "Cat.hpp"

Cat::Cat() : Animal(){
	this->type = "Cat";
	std::cout << this->type << " È nato\n";
}

Cat::Cat( const Cat &copy ) : Animal(copy){
	this->type = "Cat";
	std::cout << this->type << " È nato\n";
}

Cat::~Cat(){
	std::cout << this->type << " È scappato con l'eredità\n";
}

Cat	&Cat::operator=( const Cat &copy ){
	if (this != &copy)
		this->type = copy.type;
	return (*this);
}

void	Cat::makeSound() const{
	std::cout << "𝓜𝓮𝓸𝔀\n";
}