/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:14:31 by sde-silv          #+#    #+#             */
/*   Updated: 2024/08/05 16:29:21 by sde-silv         ###   ########.fr       */
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
	std::cout << "default constructor.\n";
	hitPoints = SCAV_HIT_POINTS;
	energyPoints = SCAV_ENERGY_POINTS;
	attackDamage = SCAV_DAMAGE_POINTS;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << this->get_class_name() << " ";
	std::cout << "constructor.\n";
	hitPoints = SCAV_HIT_POINTS;
	energyPoints = SCAV_ENERGY_POINTS;
	attackDamage = SCAV_DAMAGE_POINTS;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << this->get_class_name() << " ";
	std::cout << "destructor.\n";
}

// Copy Constructor
ScavTrap::ScavTrap(const ScavTrap& other)
{
	std::cout << this->get_class_name() << " ";
	std::cout << "copy constructor.\n";
	name = other.name;
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	attackDamage = other.attackDamage;
}

//Copy assignment overload
ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << this->get_class_name() << " ";
	std::cout << "copy assignment overload.\n";
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