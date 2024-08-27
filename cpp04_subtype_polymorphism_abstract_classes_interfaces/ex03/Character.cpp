/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:57:11 by sde-silv          #+#    #+#             */
/*   Updated: 2024/08/27 16:07:56 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/**
 * Orthodox canonical form functions
 * 
 * 1. Default constructor
 * 2. Destructor
 * 3. Copy constructor
 * 4. Copy assignment operator overload
 */
Character::Character(void): ICharacter()
{
	debug(std::cout << "Character default constructor." << std::endl);
	this->_name = "Default";
	for (int i = 0; (i < INVENTORY_SIZE); i ++)
		this->_inventory[i] = NULL;
	for (int i = 0; (i < STASH_SIZE); i ++)
		this->_stash[i] = NULL;
}

Character::~Character(void)
{
	debug(std::cout << "Character destructor." << std::endl);
	for (int i = 0; (i < INVENTORY_SIZE) ; i ++)
	{
		if ( this->_inventory[i] != NULL)
		{
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
	}
	for (int i = 0; (i < STASH_SIZE) ; i ++)
	{
		if ( this->_stash[i] != NULL)
		{
			delete this->_stash[i];
			this->_stash[i] = NULL;
		}
	}
}

/**
 * Stash is not copied in the copy constructor or 
 * copy assignment operator
 */
Character::Character(const Character &other): ICharacter()
{
	debug(std::cout << "Character copy constructor" << std::endl);
	for (int i = 0; (i < INVENTORY_SIZE); i ++)
	{
		if (other._inventory[i] != NULL)
		{
			if (this->_inventory[i] != NULL)
				this->_inventory[i] = other._inventory[i]->clone();
		}
		else
			this->_inventory[i] = NULL;
	}
	this->_name = other._name;
}

Character &Character::operator=(const Character &other)
{
	debug(std::cout << "Character copy assignment operator overload." << std::endl);
	for (int i = 0; (i < INVENTORY_SIZE); i ++)
	{
		if (other._inventory[i] != NULL)
		{
			if (this->_inventory[i] != NULL)
			{
				delete this->_inventory[i];
			}
			this->_inventory[i] = other._inventory[i]->clone();
		}
		else
			this->_inventory[i] = NULL;
	}
	this->_name = other._name;
	return (*this);
}

/**
 *  name constructor
 */
Character::Character(std::string name): ICharacter()
{
	debug(std::cout << "Character name constructor." << std::endl);
	this->_name = name;
	for (int i = 0; (i < INVENTORY_SIZE); i ++)
		this->_inventory[i] = NULL;
	for (int i = 0; (i < STASH_SIZE); i ++)
		this->_stash[i] = NULL;
}

/**
 * member function equip
 * store the materia pointer by m in the first available slot
 * of _inventory
 * 
 * (*m) doesn't need to be cloned as per subject tests
 * because m is a AMateria * we assume it is already in the heap
 */
void Character::equip(AMateria *m)
{
	for (int i = 0; (i < INVENTORY_SIZE); i ++)
	{
		if (this->_inventory[i] == NULL && m != NULL)
		{
			this->_inventory[i] = m;
			return;
		}
	}
	if (m == NULL)
		debug(std::cout << "\t\t\tnull pointer" << std::endl);
	else
		debug(std::cout << "\t\t\tInventory full" << std::endl);
}

/**
 * member function unequip
 * move the materia at _inventory[idx] to stash
 * do not delete materia
 * lst.insertNode(this->_inventory[idx]);
 */
void	Character::unequip(int idx)
{
	if (idx < INVENTORY_SIZE && idx >= 0 && this->_inventory[idx] != NULL)
	{
		for (int i = 0; i < STASH_SIZE; i++)
		{
			if (this->_stash[i] == NULL)
			{
				this->_stash[i] = this->_inventory[idx];
				this->_inventory[idx] = NULL;
				return;
			}			
		}
		debug(std::cout << "\t\t\tstash is full" << std::endl);
	}
	else if (idx >= INVENTORY_SIZE || idx < 0)
		debug(std::cout << "\t\t\tidx out of range" << std::endl);
	else
		debug(std::cout << "\t\t\tno materia at idx" << idx << std::endl);
}

/**
 * getter for Character _name
 */
std::string const	&Character::getName(void) const
{
	return (this->_name);
}

/**
 * member function use
 * use the materia at idx on target
 */
void	Character::use(int idx, ICharacter &target)
{
	if (idx < INVENTORY_SIZE && idx >= 0 && this->_inventory[idx] != NULL)
	{
		this->_inventory[idx]->use(target);
		this->unequip(idx);
		return;
	}
	else if (idx >= INVENTORY_SIZE || idx < 0)
		debug(std::cout << "\t\t\tidx out of range" << std::endl);
	else
		debug(std::cout << "\t\t\tno materia at idx" << idx << std::endl);
}
