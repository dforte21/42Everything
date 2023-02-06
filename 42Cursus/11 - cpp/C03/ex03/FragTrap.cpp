#include "FragTrap.hpp"

FragTrap::FragTrap( std::string name ) : ClapTrap(name){
	std::cout << "FragTrap " << this->getName() << " dasha nell'azione\n";
	this->setHp(100);
	this->setEp(100);
	this->setAd(30);
}

FragTrap::FragTrap( void ) : ClapTrap(){
	std::cout << "FragTrap " << this->getName() << " dasha nell'azione\n";
	this->setHp(100);
	this->setEp(100);
	this->setAd(30);
}

FragTrap::FragTrap( const FragTrap &copy ) : ClapTrap(copy){
	std::cout << "FragTrap " << this->getName() << " dasha nell'azione\n";	
}

FragTrap::~FragTrap( void ){
	std::cout << "FragTrap " << this->getName() << " viene reverse kickato via dalle palle\n";
}

FragTrap	&FragTrap::operator=( const FragTrap &copy ){
	if (this == &copy)
		return (*this);
	return (*new(this) FragTrap(copy.getName()));
}

void	FragTrap::highFivesGuys( void ){
	std::cout << "FragTrap " << this->getName() << " vuole darti il cinque :)\n";
}