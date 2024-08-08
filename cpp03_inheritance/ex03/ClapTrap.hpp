/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:14:55 by sde-silv          #+#    #+#             */
/*   Updated: 2024/08/08 19:27:03 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <typeinfo>

# define CLAP_HIT_POINTS 10
# define CLAP_ENERGY_POINTS 10
# define CLAP_DAMAGE_POINTS 0

class ClapTrap
{
	public:
		ClapTrap(void);
		virtual ~ClapTrap(void);
		ClapTrap(const ClapTrap& other);
		ClapTrap&				operator=(const ClapTrap& other);
		ClapTrap(std::string new_name);

		void 					attack(const std::string& target);
		void 					takeDamage(unsigned int amount);
		void 					beRepaired(unsigned int amount);
		unsigned int			getAttackDamage(void);
		void					print_score(void);
		virtual std::string		get_class_name(void);
		
	protected:
		std::string 	name;
		unsigned int	hitPoints;
		unsigned int	energyPoints;
		unsigned int	attackDamage;
};

#endif
