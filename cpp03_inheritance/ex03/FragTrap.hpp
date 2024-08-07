/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:14:39 by sde-silv          #+#    #+#             */
/*   Updated: 2024/08/08 19:28:32 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>
# include <typeinfo>

# define FRAG_HIT_POINTS 100
# define FRAG_ENERGY_POINTS 100
# define FRAG_DAMAGE_POINTS 30

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap(void);
		~FragTrap(void);
		FragTrap(const FragTrap& other);
		FragTrap& 		operator=(const FragTrap& other);
		FragTrap(std::string new_name);

		void			highFivesGuys(void);
		std::string		get_class_name(void);
		void 			attack(const std::string& target);
};

#endif
