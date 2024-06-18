#include "Zombie.hpp"

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n";
}

Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout << this->name << " created\n";
}

Zombie::Zombie(void)
{
	std::cout << "created\n";
}

Zombie::~Zombie(void)
{
	std::cout << this->name << " deleted\n";
}