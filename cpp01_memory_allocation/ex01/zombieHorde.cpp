#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *Horde = new Zombie[N];
	int i = 0;

	while (i < N)
	{
		Horde[i].setName(name);
		i ++;
	}
	return (Horde);
}