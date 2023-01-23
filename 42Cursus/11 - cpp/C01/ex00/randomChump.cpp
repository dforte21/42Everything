#include "Zombie.hpp"

void Zombie::randomChump( std::string name ){
	Zombie *ptr;

	ptr = this->newZombie(name);
	std::cout << ptr->name << std::endl;
	delete(ptr);
}