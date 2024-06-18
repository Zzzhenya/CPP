#include "Zombie.hpp"
#include <iostream>

int main(void)
{
	Zombie *zomb1;
	Zombie *zomb2;
	Zombie *zomb3;

	std::cout << "\nZombies incoming!!!\n" << std::endl;

	std::cout << "Zombies with names.." << std::endl;

	std::cout << "\tHeap Zombies.." << std::endl;
	zomb1 = new Zombie("Aaaaa");
	zomb1->announce();
	zomb2 = new Zombie("Baaaa");
	zomb2->announce();
	zomb3 = new Zombie("Caaaa");
	zomb3->announce();

	std::cout << "\nDeleting.." << std::endl;
	delete zomb1;
	delete zomb2;
	delete zomb3;

	std::cout << "\tStack Zombies.." << std::endl;

	Zombie zombstack = Zombie("Stacky1");
	zombstack.announce();
	Zombie zombstack1 = Zombie("Stacky2");
	zombstack1.announce();

	std::cout << "\tRandos in stack" << std::endl;
	randomChump("Rando 1");
	randomChump("Rando 2");
	randomChump("Rando 42");
	return (0);
}