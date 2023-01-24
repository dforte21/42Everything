#include "HumanA.hpp"

HumanA::HumanA( void ){
	this->weapon = NULL;
}

HumanA::HumanA (std::string name, Weapon &weapon){
	this->name = name;
	this->weapon = &weapon;
}

HumanA::~HumanA( void ){
	std::cout << this->name << ": \"Change the world, my final message, bye bye \"\n";
}

void	HumanA::attack( void ){
	if (!this->weapon)
		std::cout << this->name << " s'attacca ar cazzo (non ha un arma)";
	else
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}
