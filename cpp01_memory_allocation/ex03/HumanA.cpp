#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon& arm ) : arm(arm)
{
	this->name = name;
	// std::cout << "HumanA constructor called.\t" << " Name: " << this->name;
	// std::cout << "\tArmed: " << this->arm.getType() << "\n";
	return ;
}

HumanA::~HumanA(void)
{
	// std::cout << "HumanA destructor called.\t" << " Name: " << this->name;
	// std::cout << "\tArmed: " << this->arm.getType() << "\n";
}

//<name> attacks with their <weapon type>

void	HumanA::attack(void)
{
	std::cout << this->name << " ";
	std::cout << "attacks with their " << this->arm.getType() << "\n";
}