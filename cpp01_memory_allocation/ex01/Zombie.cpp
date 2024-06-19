#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "constructed.\n";
}

Zombie::~Zombie(void)
{
	std::cout << this->name << " destructed.\n";
}

Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout << this->name << " constructed.\n";
}

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n";
}

void	Zombie::setName(std::string name)
{
	this->name = name;
}
