#include "Zombie.hpp"

Zombie* Zombie::newZombie( std::string name ){
	Zombie *ptr = new(Zombie);

	ptr->name = name;
	return (ptr);
}