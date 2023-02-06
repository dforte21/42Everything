#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) : name("SenzaNome"){
	this->FragTrap::setHp(FragTrap::getHp());
	this->ScavTrap::setEp(ScavTrap::getEp());
	this->FragTrap::setAd(FragTrap::getAd());
	ClapTrap::setName(name + "_clap_name");
	std::cout << "DiamondTrap " << this->name << " tippa in mezzo al team nemico\n";
}

DiamondTrap::DiamondTrap( std::string _name) : name(_name){
	this->FragTrap::setHp(FragTrap::getHp());
	this->ScavTrap::setEp(ScavTrap::getEp());
	this->FragTrap::setAd(FragTrap::getAd());
	ClapTrap::setName(name + "_clap_name");
	std::cout << "DiamondTrap " << this->name << " tippa in mezzo al team nemico\n";
}

DiamondTrap::DiamondTrap( const DiamondTrap &copy ){
	*this = copy;
	std::cout << "DiamondTrap " << this->name << " tippa in mezzo al team nemico\n";
}

DiamondTrap::~DiamondTrap( void ){
	std::cout << "DiamondTrap " << this->name << " muore come uno stronzo e flamma il team\n";
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &copy ){
	if (this == &copy)
		return (*this);
	return (*new(this) DiamondTrap(copy.name));
}

void	DiamondTrap::whoAmI(){
	std::cout << "Io sono " << this->name << " ma anche " << ClapTrap::getName() << std::endl;
}

void	DiamondTrap::attack( const std::string &target ){
	ScavTrap::attack(target);
}