#include "ScavTrap.hpp"

int main()
{
	ScavTrap	c1("Giorgio");
	ScavTrap	c2("Tanacca");
	ScavTrap	c3 = c1;

	c1.attack("Tanacca");
	c2.attack("Giorgio");
	c3.attack("awanasghena");
	c1.guardGate();
	c2.guardGate();
	c3.guardGate();
}