#include "HumanB.hpp"

HumanB::HumanB( void ){
	this->weapon = NULL;
}

HumanB::HumanB (std::string name){
	this->weapon = NULL;
	this->name = name;
}

HumanB::~HumanB( void ){
	std::cout << this->name << ": \"Change the world, my final message, bye bye \"\n";
}

void	HumanB::attack( void ){
	if (!this->weapon)
		std::cout << this->name << " s'attacca ar cazzo (non ha un arma)";
	else
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

void	HumanB::setWeapon( Weapon &weapon ){
	this->weapon = &weapon;
}
