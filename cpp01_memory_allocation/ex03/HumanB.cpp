#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	
	// std::cout << "HumanB constructor called.\t" << " Name: " << this->name;
	// std::cout << "\tArmed: " << this->arm.getType() << "\n";
}

HumanB::~HumanB(void)
{
	// std::cout << "HumanB destructor called.\t" << " Name: " << this->name;
	// std::cout << "\tArmed: " << this->arm.getType() << "\n";
}

//<name> attacks with their <weapon type>

void	HumanB::attack(void)
{
	std::cout << this->name << " ";
	std::cout << "attacks with their " << this->arm->getType() << "\n";
}

void	HumanB::setWeapon(Weapon& arm)
{
	this->arm = &arm;
	// std::cout << this->name << " ";
	// std::cout << "armed with " << this->arm.getType() << "\n";
}