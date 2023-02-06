#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap	c1("TeChaiNaBotta");
	DiamondTrap	c2("Tanacca");
	DiamondTrap	c3 = c1;

	c1.attack("Tanacca");
	c2.attack("TeChaiNaBotta");
	c3.attack("awanasghena");
	c1.whoAmI();
	c2.whoAmI();
	c3.whoAmI();
}