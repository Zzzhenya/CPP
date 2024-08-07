/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:14:39 by sde-silv          #+#    #+#             */
/*   Updated: 2024/08/08 16:47:40 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>
# include <typeinfo>

# define SCAV_HIT_POINTS 100
# define SCAV_ENERGY_POINTS 50
# define SCAV_DAMAGE_POINTS 20

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(void);
		~ScavTrap(void);
		ScavTrap(const ScavTrap& other);
		ScavTrap& 		operator=(const ScavTrap& other);
		ScavTrap(std::string new_name);

		void			guardGate(void);
		std::string		get_class_name(void);
		void 			attack(const std::string& target);
};

#endif