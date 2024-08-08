/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:14:31 by sde-silv          #+#    #+#             */
/*   Updated: 2024/08/08 19:28:50 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

std::string	DiamondTrap::get_class_name(void)
{
	std::string c_name = typeid(this).name();
	
	if (c_name[0] == 'P')
		return(&typeid(this).name()[3]);
	else
		return(&typeid(this).name()[2]);
}

DiamondTrap::DiamondTrap() : ClapTrap()
{
	this->name = "Default_D";
	hitPoints = FragTrap::hitPoints;
	energyPoints = SCAV_ENERGY_POINTS;
	attackDamage = FragTrap::attackDamage;
	std::cout << this->get_class_name() << " ";
	std::cout << this->name << " ";
	std::cout << "constructor.\n";
}

DiamondTrap::DiamondTrap(std::string new_name) : ClapTrap(new_name + "_clap_name")
{
	this->name = new_name;
	hitPoints = FragTrap::hitPoints;
	energyPoints = SCAV_ENERGY_POINTS;
	attackDamage = FragTrap::attackDamage;
	std::cout << this->get_class_name() << " ";
	std::cout << this->name << " ";
	std::cout << "constructor.\n";
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << this->get_class_name() << " ";
	std::cout << this->name << " ";
	std::cout << "destructor.\n";
}

// Copy Constructor
DiamondTrap::DiamondTrap(const DiamondTrap& other): ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	std::cout << this->get_class_name() << " ";
	std::cout << this->name << " ";
	std::cout << "copy constructor.\n";
}

//Copy assignment overload
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << this->get_class_name() << " ";
	std::cout << this->name << " ";
	std::cout << "copy assignment overload.\n";
	name = other.name;
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	attackDamage = other.attackDamage;
	return (*this);
}

void 	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << get_class_name() << " ";
	std::cout << "name: \t" << name << "\t";
	std::cout << "ClapTrap name: " << ClapTrap::name << std::endl;
}
