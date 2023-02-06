#include "ClapTrap.hpp"

int main()
{
	ClapTrap	c1("Giorgio");
	ClapTrap	c2("Tanacca");

	c1.attack("Tanacca");
	c2.takeDamage(c1.getAd());
	c2.beRepaired(c1.getAd());
	c2.attack("Giorgio");
	c1.takeDamage(c2.getAd());
	c1.beRepaired(c2.getAd());
}