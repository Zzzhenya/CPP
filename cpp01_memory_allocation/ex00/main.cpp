#include "Zombie.hpp"
#include <iostream>

int main(void)
{
	std::cout << "Zombies incoming!!!" << std::endl;

	Zombie *zomb1;
	Zombie *zomb2;
	Zombie *zomb3;

	zomb1 = new Zombie("Aaaaa");
	zomb1->announce();
	zomb2 = new Zombie("Baaaa");
	zomb2->announce();
	zomb3 = new Zombie("Caaaa");
	zomb3->announce();
	delete zomb1;
	delete zomb2;
	delete zomb3;
	return (0);
}