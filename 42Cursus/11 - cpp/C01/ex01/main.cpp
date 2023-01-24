#include "Zombie.hpp"

int main()
{
	Zombie *zmb = NULL;
	Zombie *zmb1 = NULL;
	Zombie *zmb2 = NULL;
	
	zmb = zmb->zombieHorde(1, "Techainabotta");
	zmb1 = zmb1->zombieHorde(2, "GMEEEEEEEEEEEEEEEEEEEOLI");
	zmb2 = zmb2->zombieHorde(3, "DAGRSETGEA");

	for (int i = 0; i < 1; i++)
		zmb[i].announce();
	for (int i = 0; i < 2; i++)
		zmb1[i].announce();
	for (int i = 0; i < 3; i++)
		zmb2[i].announce();
	delete[] zmb;
	delete[] zmb1;
	delete[] zmb2;
}