#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "ICharacter.hpp"
# include "AMateria.hpp"
# include "Ice.hpp"
# include "Cure.hpp"

# define INVENTORY_SIZE 4

class Character: public ICharacter
{
	public:
		Character(void);
		~Character(void);
		Character(const Character &other);
		// Character operator=(const Character &other);
		Character(std::string name);

		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);
		std::string const &getName() const;

	private:
		AMateria 		*_inventory[INVENTORY_SIZE];
		std::string 	_name;

};

#endif