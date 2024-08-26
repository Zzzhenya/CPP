#include "Character.hpp"

Character::Character(void): ICharacter()
{
	debug(std::cout << "Character default constructor." << std::endl);
	this->_name = "Default";
	for (int i = 0; (i < INVENTORY_SIZE); i ++)
		this->_inventory[i] = NULL;
	for (int i = 0; (i < STASH_SIZE); i ++)
		this->_stash[i] = NULL;
}

Character::Character(std::string name): ICharacter()
{
	debug(std::cout << "Character name constructor." << std::endl);
	this->_name = name;
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
			delete this->_inventory[i];
	}
	for (int i = 0; (i < STASH_SIZE) ; i ++)
	{
		if ( this->_stash[i] != NULL)
			delete this->_stash[i];
	}
}

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
				this->_inventory[i] = other._inventory[i]->clone();
			}
		}
		else
			this->_inventory[i] = NULL;
	}
	this->_name = other._name;
	return (*this);
}

// (*m) doesn't need to be cloned as per subject tests
// because m is a AMateria * we assume it is already in the heap
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
	debug(std::cout << "\t\t\tInventory full" << std::endl);
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
				return;
			}			
		}
		debug(std::cout << "\t\t\tstash is full" << std::endl);
		//lst.insertNode(this->_inventory[idx]);
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
		this->_inventory[idx]->use(target);
		this->unequip(idx);
		return;
	}
	debug(std::cout << "\t\t\t\t\tError\n");
}