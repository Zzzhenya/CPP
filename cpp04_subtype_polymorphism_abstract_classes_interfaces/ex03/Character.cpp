#include "Character.hpp"

Character::Character(void): ICharacter()
{
	std::cout << "Character default constructor." << std::endl; 
	this->_name = "Default";
	for (int i = 0; (i < INVENTORY_SIZE); i ++)
		this->_inventory[i] = NULL;
}

Character::Character(std::string name): ICharacter()
{
	std::cout << "Character name constructor." << std::endl; 
	this->_name = name;
	for (int i = 0; (i < INVENTORY_SIZE); i ++)
		this->_inventory[i] = NULL;
}

Character::~Character(void)
{
	std::cout << "Character destructor." << std::endl;
	for (int i = 0; (i < INVENTORY_SIZE) ; i ++)
	{
		if ( this->_inventory[i] != NULL)
			delete this->_inventory[i];
	}
}

Character::Character(const Character &other)
{
	std::cout << "Character copy constructor" << std::endl;
	for (int i = 0; (i < INVENTORY_SIZE); i ++)
	{
		if (this->_inventory[i] != NULL)
		{
			delete this->_inventory[i];
			this->_inventory[i] = other._inventory[i]->clone();
		}
	}
}

// Character Character::operator=(const Character &other)
// {
// 	std::cout << "Character copy assignment operator overload." << std::endl;
// 	for (int i = 0; (i < INVENTORY_SIZE); i ++)
// 	{
// 		if (this->_inventory[i] != NULL)
// 		{
// 			delete this->_inventory[i];
// 			this->_inventory[i] = other._inventory[i]->clone();
// 		}
// 	}
// 	return (*this);
// }

// (*)m is cloned to make sure to avoid double free
void Character::equip(AMateria *m)
{
	for (int i = 0; (i < INVENTORY_SIZE); i ++)
	{
		if (this->_inventory[i] == NULL && m != NULL)
		{
			this->_inventory[i] = (*m).clone();
			break;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < INVENTORY_SIZE && idx >= 0 && this->_inventory[idx] != NULL)
	{
		// store_in_stash(this->_inventory[idx]);
		this->_inventory[idx] = NULL;
	}
}

std::string const &Character::getName(void) const
{
	return (this->_name);
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < INVENTORY_SIZE && idx >= 0 && this->_inventory[idx] != NULL)
	{
		// this->_inventory[idx]->use(target);
		if (this->_inventory[idx]->getType() == TYPE_ICE)
		{
			std::cout << "Ice: \"* shoots an ice bolt at ";
			std::cout << target.getName();
			std::cout << " *\"" << std::endl;

			this->unequip(idx);
		}
		else if (this->_inventory[idx]->getType() == TYPE_CURE)
		{
			std::cout << "Cure: \"* heals ";
			std::cout << target.getName();
			std::cout << "’s wounds *\"" << std::endl;
			this->unequip(idx);
		}
	}
}