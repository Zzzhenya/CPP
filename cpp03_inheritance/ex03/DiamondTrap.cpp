/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:14:31 by sde-silv          #+#    #+#             */
/*   Updated: 2024/08/06 20:31:52 by sde-silv         ###   ########.fr       */
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

// DiamondTrap::DiamondTrap(void) : FragTrap(),  ScavTrap()
// {
// 	this->name = "DT";
// 	std::cout << this->get_class_name() << " ";
// 	std::cout << "default constructor.\n";
// 	//hitPoints = FragTrap::hitPoints;
// 	hitPoints = FRAG_HIT_POINTS;
// 	energyPoints = ScavTrap::energyPoints;
// 	//attackDamage = FragTrap::attackDamage;
// 	attackDamage = FRAG_DAMAGE_POINTS;
	
// }

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name")
{
	this->name = name;
	hitPoints = FragTrap::hitPoints;
	energyPoints = ScavTrap::energyPoints;
	attackDamage = FragTrap::attackDamage;
	std::cout << this->get_class_name() << " ";
	std::cout << this->name << " ";
	std::cout << "constructor.\n";
}

// DiamondTrap::DiamondTrap(std::string name) : FragTrap(name),  ScavTrap(name)
// {
// 	std::cout << this->get_class_name() << " ";
// 	std::cout << this->name << " ";
// 	std::cout << "constructor.\n";
// 	this->name = name;
// 	hitPoints = FragTrap::hitPoints;
// 	energyPoints = ScavTrap::energyPoints;
// 	attackDamage = FragTrap::attackDamage;
// }

DiamondTrap::~DiamondTrap(void)
{
	std::cout << this->get_class_name() << " ";
	std::cout << this->name << " ";
	std::cout << "destructor.\n";
}

// Copy Constructor
DiamondTrap::DiamondTrap(const DiamondTrap& other)
{
	std::cout << this->get_class_name() << " ";
	std::cout << this->name << " ";
	std::cout << "copy constructor.\n";
	name = other.name;
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	attackDamage = other.attackDamage;
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
