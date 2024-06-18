#include "Zombie.hpp"

/*
	RandomChump in stack
*/
void randomChump( std::string name )
{
	Zombie Chump = Zombie(name);
	Chump.announce();
}
/*
	RandomChump in heap;

void randomChump( std::string name )
{
	Zombie *randomChump;

	randomChump = new Zombie(name);
	randomChump->announce();
	delete randomChump;
}
*/