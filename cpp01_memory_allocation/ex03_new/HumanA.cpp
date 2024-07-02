#include "HumanA.hpp"

void HumanA::attack(void)
{
	std::cout << this->name << " ";
	std::cout << "attacks with their ";
	std::cout << this->arm.getType() << std::endl;
}

HumanA::HumanA(std::string name, Weapon &arm) : name(name), arm(arm)
{}