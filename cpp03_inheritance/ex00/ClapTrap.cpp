/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:32:34 by sde-silv          #+#    #+#             */
/*   Updated: 2024/08/06 22:01:34 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

std::string	ClapTrap::get_class_name(void)
{
	std::string c_name = typeid(this).name();
	
	if (c_name[0] == 'P')
		return(&typeid(this).name()[2]);
	else
		return(&typeid(this).name()[1]);
}

ClapTrap::ClapTrap(void)
{
	this->name = "Default";
	this->hitPoints = CLAP_HIT_POINTS;
	this->energyPoints = CLAP_ENERGY_POINTS;
	this->attackDamage = CLAP_DAMAGE_POINTS;
	std::cout << (*this).get_class_name() << " ";
	std::cout << this->name << " Default constructor." << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
{
	this->name = name;
	this->hitPoints = CLAP_HIT_POINTS;
	this->energyPoints = CLAP_ENERGY_POINTS;
	this->attackDamage = CLAP_DAMAGE_POINTS;
	std::cout << (*this).get_class_name() << " ";
	std::cout << this->name << " Constructor." << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << (*this).get_class_name() << " ";
	std::cout << this->name << " Default destructor." << std::endl;
}

/*Copy constructor*/
ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << (*this).get_class_name() << " ";
	std::cout << this->name << " Copy constructor." << std::endl;
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << (*this).get_class_name() << " ";
	std::cout << this->name << " Copy assignment operator overload." << std::endl;
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
	return (*this);
}

void	ClapTrap::print_score(void)
{
	std::cout << name \
		<<" :\tHit:" << hitPoints << "\t\tE:" << energyPoints 
		<< "\t\tDamage:" << attackDamage << std::endl;
}

unsigned int	ClapTrap::getAttackDamage(void)
{
	return (this->attackDamage);
}

void	ClapTrap::attack(const std::string& target)
{
	if (energyPoints > 0 && hitPoints > 0)
	{
		std::cout << this->get_class_name() << " " << name \
				<< " attacks " << target \
				<< " , causing " << attackDamage \
				<< " points of damage!" << std::endl;
		energyPoints--;
	}
	else if (this->hitPoints <= 0)
		std::cout << this->get_class_name() << " " << name \
			<< " out of hit points." << std::endl;
	else
		std::cout << this->get_class_name() << " " << name \
			<< " out of energy." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if ((hitPoints > 0) && (energyPoints > 0))
	{
		std::cout << this->get_class_name() << " " << name \
			<< " repairs, gaining "<< amount \
			<< " points!" << std::endl;
		hitPoints += amount;
		energyPoints--;
	}
	else if (energyPoints == 0)
		std::cout << this->get_class_name() << " " << name \
			<< " out of energy." << std::endl;
	else
		std::cout << this->get_class_name() << " " << name \
			<< " out of hit points" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if ((hitPoints > 0) && (energyPoints > 0))
	{
		std::cout << (*this).get_class_name() << " " << name \
			<< " took damage, losing "<< amount \
			<< " points!" << std::endl;
		if (hitPoints - amount >= 0)	
			hitPoints -= amount;
		else
			hitPoints = 0;
	}
	else if (energyPoints == 0)
		std::cout << this->get_class_name() << " " << name \
			<< " out of energy." << std::endl;
	else
		std::cout << this->get_class_name() << " " << name \
			<< " out of hit points" << std::endl;
}