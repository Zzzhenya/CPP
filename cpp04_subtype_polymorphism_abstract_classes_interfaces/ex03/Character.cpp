#include "Character.hpp"

Character::Character(void): ICharacter()
{
	std::cout << "Character default constructor." << std::endl; 
	this->_name = "Default";
	for (int i = 0; (i < INVENTORY_SIZE); i ++)
		this->_inventory[i] = NULL;
	for (int i = 0; (i < STASH_SIZE); i ++)
		this->_stash[i] = NULL;
}

Character::Character(std::string name): ICharacter()
{
	std::cout << "Character name constructor." << std::endl; 
	this->_name = name;
	for (int i = 0; (i < INVENTORY_SIZE); i ++)
		this->_inventory[i] = NULL;
	for (int i = 0; (i < STASH_SIZE); i ++)
		this->_stash[i] = NULL;
}

Character::~Character(void)
{
	std::cout << "Character destructor." << std::endl;
	for (int i = 0; (i < INVENTORY_SIZE) ; i ++)
	{
		if ( this->_inventory[i] != NULL)
			delete this->_inventory[i];
	}
	for (int i = 0; (i < STASH_SIZE) ; i ++)
	{
		if ( this->_stash[i] != NULL)
			delete this->_stash[i];
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
	for (int i = 0; (i < STASH_SIZE); i ++)
	{
		if (this->_stash[i] != NULL)
		{
			delete this->_stash[i];
			this->_stash[i] = other._stash[i]->clone();
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
		else if (this->_inventory[i] != NULL && m != NULL && i == INVENTORY_SIZE - 1)
				std::cout << "\t\t\tInventory full" << std::endl;
	}
}

void Character::unequip(int idx)
{
	if (idx < INVENTORY_SIZE && idx >= 0 && this->_inventory[idx] != NULL)
	{
		for (int i = 0; i < STASH_SIZE; i++)
		{
			if (this->_stash[i] == NULL)
			{
				this->_stash[i] = this->_inventory[idx];
				this->_inventory[idx] = NULL;
				break;
			}
			else if (this->_stash[i] != NULL && i == STASH_SIZE - 1)
				std::cout << "\t\t\tstash is full" << std::endl;
		}
		//lst.insertNode(this->_inventory[idx]);
		// store_in_stash(this->_inventory[idx]);
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
	else
		std::cout << "\t\t\t\t\tError\n";
}