#include "Zombie.hpp"
#include <iostream>
#include <string>

int main(void)
{
	int count = 5;
	int i = 0;

	Zombie *horde = NULL;
	Zombie *curr;

	horde = zombieHorde(count, "Aaaaa");

	curr = horde;
	while (i < count)
	{
		std::cout << i + 1 << " ";
		curr->announce();
		i ++;
		curr ++;
	}

	delete[] horde;
	return (0);
}