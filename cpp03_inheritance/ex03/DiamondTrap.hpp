/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:14:39 by sde-silv          #+#    #+#             */
/*   Updated: 2024/08/08 19:28:43 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include <iostream>
# include <typeinfo>

class DiamondTrap : public ScavTrap,  public FragTrap
{
	public:
		DiamondTrap(void);
		~DiamondTrap(void);
		DiamondTrap(const DiamondTrap& other);
		DiamondTrap& 	operator=(const DiamondTrap& other);
		DiamondTrap(std::string new_name);

		std::string		get_class_name(void);
		void 			attack(const std::string& target);
		void			whoAmI(void);
	
	private:
		std::string 	name;
};

#endif
