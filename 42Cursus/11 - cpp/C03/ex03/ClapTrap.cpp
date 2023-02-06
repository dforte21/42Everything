#include "ClapTrap.hpp"

ClapTrap::ClapTrap( std::string name ){
	this->name = name;
	this->hP = 10;
	this->eP = 10;
	this->aD = 0;
	std::cout << "ClapTrap " << this->name << " sorge\n";
}

ClapTrap::ClapTrap( void ){
	this->name = "SenzaNome";
	this->hP = 10;
	this->eP = 10;
	this->aD = 0;
	std::cout << "ClapTrap " << this->name << " sorge\n";
}

ClapTrap::ClapTrap( const ClapTrap &copy ){
	*this = copy;
	std::cout << "ClapTrap " << this->name << " sorge\n";
}

ClapTrap::~ClapTrap( void ){
	std::cout << "ClapTrap " << this->name << " :\"LMAO, my final message, bye bye\"\n";
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &copy){
	if (this == &copy)
		return (*this);
	this->name = copy.name;
	this->aD = copy.aD;
	this->eP = copy.eP;
	this->hP = copy.hP;
	return (*this);
}

void	ClapTrap::attack(const std::string& target){
	if (this->hP <= 0)
		std::cout << "ClapTrap " << this->name << " is dead\n";
	else if (this->eP > 0)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << " causing " << this->aD << " points of damage\n";
		this->eP--;
	}
	else
		std::cout << "ClapTrap " << this->name << " is very hungry, can't do anything(non ha eP)\n";
}

void	ClapTrap::takeDamage(uint amount){
	std::cout << "ClapTrap " << this->name << " gets hit for " << amount << " points of damage\n";
	this->hP -= amount;
	if (this->hP <= 0)
		std::cout << "ClapTrap " << this->name << " is dead\n";
}

void	ClapTrap::beRepaired(uint amount){
	if (this->hP <= 0)
		std::cout << "ClapTrap " << this->name << " is dead\n";
	else if (this->eP > 0)
	{
		std::cout << "ClapTrap " << this->name << " repairs itself for " << amount << " hP\n";
		this->hP += amount;
		this->eP--;
	}
	else
		std::cout << "ClapTrap " << this->name << " is very hungry, can't do anything(non ha eP)\n";	
}

uint	ClapTrap::getAd( void ) const{
	return (this->aD);
}

std::string	ClapTrap::getName( void ) const{
	return (this->name);
}

uint	ClapTrap::getHp( void ) const{
	return (this->hP);
}

uint	ClapTrap::getEp( void ) const{
	return (this->eP);
}

void	ClapTrap::setHp( uint hp ){
	this->hP = hp;
}

void	ClapTrap::setEp( uint ep ){
	this->eP = ep;
}

void	ClapTrap::setAd( uint ad ){
	this->aD = ad;
}

void	ClapTrap::setName( std::string name ){
	this->name = name;
}