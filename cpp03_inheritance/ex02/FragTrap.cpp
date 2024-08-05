/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:14:31 by sde-silv          #+#    #+#             */
/*   Updated: 2024/08/05 21:40:27 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

std::string	FragTrap::get_class_name(void)
{
	std::string c_name = typeid(this).name();
	
	if (c_name[0] == 'P')
		return(&typeid(this).name()[2]);
	else
		return(&typeid(this).name()[1]);
}

FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << this->get_class_name() << " ";
	std::cout << "default constructor.\n";
	hitPoints = FRAG_HIT_POINTS;
	energyPoints = FRAG_ENERGY_POINTS;
	attackDamage = FRAG_DAMAGE_POINTS;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << this->get_class_name() << " ";
	std::cout << "constructor.\n";
	hitPoints = FRAG_HIT_POINTS;
	energyPoints = FRAG_ENERGY_POINTS;
	attackDamage = FRAG_DAMAGE_POINTS;
}

FragTrap::~FragTrap(void)
{
	std::cout << this->get_class_name() << " ";
	std::cout << "destructor.\n";
}

// Copy Constructor
FragTrap::FragTrap(const FragTrap& other)
{
	std::cout << this->get_class_name() << " ";
	std::cout << "copy constructor.\n";
	name = other.name;
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	attackDamage = other.attackDamage;
}

//Copy assignment overload
FragTrap& FragTrap::operator=(const FragTrap& other)
{
	std::cout << this->get_class_name() << " ";
	std::cout << "copy assignment overload.\n";
	name = other.name;
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	attackDamage = other.attackDamage;
	return (*this);
}

void FragTrap::highFivesGuys(void)
{
	std::cout << this->get_class_name() << " ";
	std::cout << name << " high fives guys." << std::endl;
}