#include "FragTrap.hpp"

int main()
{
	FragTrap	c1("Giorgio");
	FragTrap	c2("Tanacca");
	FragTrap	c3 = c1;

	c1.attack("Tanacca");
	c2.attack("Giorgio");
	c3.attack("awanasghena");
	c1.highFivesGuys();
	c2.highFivesGuys();
	c3.highFivesGuys();
}