/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:57:18 by sde-silv          #+#    #+#             */
/*   Updated: 2024/08/27 16:24:34 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "ICharacter.hpp"
# include "AMateria.hpp"
# include "Ice.hpp"
# include "Cure.hpp"
# include "debug.hpp"

# define INVENTORY_SIZE 4
# define STASH_SIZE 100

class Character: public ICharacter
{
	public:
		Character(void);
		~Character(void);
		Character(const Character &other);
		Character(std::string name);
		Character			&operator=(const Character &other);

		void				equip(AMateria *m);
		void				unequip(int idx);
		void				use(int idx, ICharacter &target);
		std::string const	&getName() const;

	private:
		AMateria			*_inventory[INVENTORY_SIZE];
		std::string			_name;
		AMateria			*_stash[STASH_SIZE];

};

#endif