#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	std::cout << "Default constructor." << std::endl;
	this->name = "Default";
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
}

ClapTrap::ClapTrap(const std::string& name)
{
	std::cout << "Constructor." << std::endl;
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Default destructor." << std::endl;
}

/*Copy constructor*/
ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "Copy constructor." << std::endl;
	name = other.name;
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	attackDamage = other.attackDamage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "Copy assignment overload." << std::endl;
	name = other.name;
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	attackDamage = other.attackDamage;
	return(*this);
}

void	ClapTrap::print_score(void)
{
	std::cout << name <<" :\t" << hitPoints << "\t" << energyPoints <<"\t\t" << attackDamage << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->energyPoints > 0 && this->hitPoints > 0)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << " , causing "<< this->attackDamage << " points of damage!" << std::endl;
		this->energyPoints--;
	}
	else if (this->hitPoints <= 0)
		std::cout << "ClapTrap " << name << " out of hit points." << std::endl;
	else
		std::cout << "ClapTrap " << name << " out of energy." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints > 0)
	{
		std::cout << "ClapTrap " << this->name \
			<< " repairs, gaining "<< amount \
			<< " points!" << std::endl;
		this->hitPoints += amount;
		this->energyPoints--;
	}
	else
		std::cout << "ClapTrap " << this->name << " out of energy." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints > 0 && energyPoints > 0)
	{
		std::cout << "ClapTrap " << name \
			<< " took damage, losing "<< amount \
			<< " points!" << std::endl;
		if (hitPoints - amount >= 0)	
			hitPoints -= amount;
		else
			hitPoints = 0;
	}
	else if (energyPoints == 0)
		std::cout << "ClapTrap " << name << " out of energy." << std::endl;
	else
		std::cout << "ClapTrap " << name << " out of hit points." << std::endl;
}