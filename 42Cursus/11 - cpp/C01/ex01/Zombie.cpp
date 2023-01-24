#include "Zombie.hpp"

Zombie::Zombie( void ){
	return ;
}

Zombie::Zombie( std::string name ){
	this->name = name;
}

Zombie::~Zombie(void){
	std::cout << this->name << " Se leva dar cazzo\n";
}

void Zombie::announce(void){
	std::cout << this->name << std::endl;
}