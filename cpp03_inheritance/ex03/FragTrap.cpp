#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("Default")
{
	std::cout << "Frag default constructor." << std::endl;
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
}

FragTrap::~FragTrap(void)
{
	std::cout << "Frag default destructor." << std::endl;
}

FragTrap::FragTrap(const FragTrap& other)
{
	std::cout << "Frag copy constructor." << std::endl;
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	std::cout << "Frag copy operator overload." << std::endl;
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
	return (*this);	
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "Frag constructor." << std::endl;
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << name << " sends a positive high five request." << std::endl;
}

void	FragTrap::attack(const std::string& target)
{
	if (this->energyPoints > 0 && this->hitPoints > 0)
	{
		std::cout << "FragTrap " << this->name << " attacks " << target << " , causing "<< this->attackDamage << " points of damage!" << std::endl;
		this->energyPoints--;
	}
	else
		std::cout << "FragTrap " << this->name << " out of energy." << std::endl;
}

