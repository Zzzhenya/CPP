#include "Zombie.hpp"

void randomChump( std::string name )
{
	Zombie Chump = Zombie(name);
	Chump.announce();
}