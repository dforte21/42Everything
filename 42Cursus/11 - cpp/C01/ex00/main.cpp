#include "Zombie.hpp"

int main()
{
	Zombie zomb1("Dav");
	Zombie *zomb2;

	zomb2 = zomb1.newZombie("Gianfranco");
	zomb1.announce();
	zomb2->announce();
	zomb1.randomChump("Awanasghena");
	zomb2->randomChump("WETANACCA");
	delete(zomb2);
}