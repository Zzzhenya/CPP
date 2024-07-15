#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << "Scav default constructor.\n";
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "Scav constructor.\n";
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "Scav destructor.\n";
}

// Copy Constructor
ScavTrap::ScavTrap(const ScavTrap& other)
{
	std::cout << "Scav copy constructor.\n";
	name = other.name;
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	attackDamage = other.attackDamage;
}

//Copy assignment overload
ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "Scav copy assignment overload.\n";
	name = other.name;
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	attackDamage = other.attackDamage;
	return (*this);
}

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode." << std::endl;
}