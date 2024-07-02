#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->type = type;
}

void Weapon::setType(std::string newtype)
{
	this->type = newtype;
}

const std::string& Weapon::getType(void)
{
	//const std::string &stringREF = this->type;
	// if (this->type.empty())
	// 	std::cout << "No Type";
	//return (stringREF);
	return ((const std::string &)(this->type));
}