#include "HumanB.hpp"

HumanB::HumanB(std::string name): name(name)
{

}

void	HumanB::setWeapon(Weapon &newarm)
{
	this->arm = &newarm;
}

void HumanB::attack(void)
{
	std::cout << this->name << " ";
	std::cout << "attacks with their ";
	std::cout << this->arm->getType() << std::endl;
}