/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:14:31 by sde-silv          #+#    #+#             */
/*   Updated: 2024/08/08 19:30:23 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

std::string	ScavTrap::get_class_name(void)
{
	std::string c_name = typeid(this).name();
	
	if (c_name[0] == 'P')
		return(&typeid(this).name()[2]);
	else
		return(&typeid(this).name()[1]);
}

ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << this->get_class_name() << " ";
	std::cout << this->name << " default constructor.\n";
	hitPoints = SCAV_HIT_POINTS;
	energyPoints = SCAV_ENERGY_POINTS;
	attackDamage = SCAV_DAMAGE_POINTS;
}

ScavTrap::ScavTrap(std::string new_name) : ClapTrap(new_name)
{
	std::cout << this->get_class_name() << " ";
	std::cout << this->name << " constructor.\n";
	hitPoints = SCAV_HIT_POINTS;
	energyPoints = SCAV_ENERGY_POINTS;
	attackDamage = SCAV_DAMAGE_POINTS;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << this->get_class_name() << " ";
	std::cout << this->name << " destructor.\n";
}

// Copy Constructor
ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other)
{
	std::cout << this->get_class_name() << " ";
	std::cout << this->name << " copy constructor.\n";
}

//Copy assignment overload
ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << this->get_class_name() << " ";
	std::cout << this->name << " copy assignment overload.\n";
	name = other.name;
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	attackDamage = other.attackDamage;
	return (*this);
}

void ScavTrap::guardGate(void)
{
	std::cout << this->get_class_name() << " ";
	std::cout << name << " is now in Gate keeper mode." << std::endl;
}

void 	ScavTrap::attack(const std::string& target)
{
	if (energyPoints > 0 && hitPoints > 0)
	{
		std::cout << "ScavTrap" << " " << name \
				<< " attacks " << target \
				<< " , causing " << attackDamage \
				<< " points of damage!" << std::endl;
		energyPoints--;
	}
	else if (this->hitPoints <= 0)
		std::cout << "ScavTrap" << " " << name \
			<< " out of hit points." << std::endl;
	else
		std::cout << "ScavTrap" << " " << name \
			<< " out of energy." << std::endl;
}
