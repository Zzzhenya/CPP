#include "Weapon.hpp"

Weapon::Weapon()
{
	// std::cout << "Weapon constructor caalled.\t" << " Type: Typeless\n";
}

Weapon::~Weapon()
{
	// std::cout << "Weapon destructor called.\t" << " Type: " << this->type << "\n";
}

Weapon:: Weapon(std::string type)
{
	this->type = type;
	// std::cout << "Weapon constructor called.\t" << " Type: " << this->type << "\n";
}

const std::string	&Weapon::getType(void)
{
	return((const std::string&)(this->type));
}

void	Weapon::setType(std::string	newtype)
{
	this->type = newtype;
}