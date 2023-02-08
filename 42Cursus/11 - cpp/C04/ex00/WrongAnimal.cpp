#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : Animal(){
	std::cout << "\nWhat have you done... " << this->type << " arise\n";
}

WrongAnimal::WrongAnimal( const WrongAnimal &copy ) : Animal(copy){
	std::cout << "What have you done... " << this->type << " arise\n";
}

WrongAnimal::~WrongAnimal(){
	std::cout << "You should have never born... STAB\n";
}

WrongAnimal	&WrongAnimal::operator=( const WrongAnimal &copy ){
	if(this != &copy)
		this->type = copy.type;
	return (*this);
}