#include "ScavTrap.hpp"

ScavTrap::ScavTrap( std::string name ) : ClapTrap( name){
	std::cout << "ScavTrap " << this->getName() << " entra in scena\n";
	this->setHp(100);
	this->setEp(50);
	this->setAd(20);
}

ScavTrap::ScavTrap( void ) : ClapTrap(){
	std::cout << "ScavTrap " << this->getName() << " entra in scena\n";
	this->setHp(100);
	this->setEp(50);
	this->setAd(20);
}

ScavTrap::ScavTrap( const ScavTrap &copy) : ClapTrap( copy ){
	std::cout << "ScavTrap " << this->getName() << " entra in scena\n";
}

ScavTrap::~ScavTrap( void ){
	std::cout << "ScavTrap " << this->getName() << " vola via\n";
}

ScavTrap	&ScavTrap::operator=( const ScavTrap &copy ) {
	if (this == &copy)
		return (*this);
	return (*new(this) ScavTrap(copy.getName()));
}

void	ScavTrap::attack(const std::string& target){
	if (this->getHp() <= 0)
		std::cout << "ScavTrap " << this->getName() << " is dead\n";
	else if (this->getEp() > 0)
	{
		std::cout << "ScavTrap " << this->getName() << " attacks " << target << " causing " << this->getAd() << " points of damage\n";
		this->setEp(this->getEp() - 1);
	}
	else
		std::cout << "ScavTrap " << this->getName() << " is very hungry, can't do anything(non ha eP)\n";
}

void	ScavTrap::guardGate( void ){
	std::cout << "ScavTrap " << this->getName() << " is gate keeping\n";
}