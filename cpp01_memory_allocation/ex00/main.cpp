#include "Zombie.hpp"
#include <iostream>

int main(void)
{
	Zombie *zomb1;
	Zombie *zomb2;
	Zombie *zomb3;

	std::cout << "Zombies incoming!!!" << std::endl;

	std::cout << "Zombies with names.." << std::endl;
	zomb1 = new Zombie("Aaaaa");
	zomb1->announce();
	zomb2 = new Zombie("Baaaa");
	zomb2->announce();
	zomb3 = new Zombie("Caaaa");
	zomb3->announce();

	std::cout << "Deleting.." << std::endl;
	delete zomb1;
	delete zomb2;
	delete zomb3;

	std::cout << "Randos.." << std::endl;
	randomChump("Rando 1");
	randomChump("Rando 2");
	randomChump("Rando 42");

	return (0);
}